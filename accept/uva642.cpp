/* hash table */
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXL 10

string hash_func(char *);

int main() {
    char input[MAXL];
    bool loading = true;
    string s, h;
    map<string, vector<string> > hash_table;
    while (~scanf("%s", input)) {
        s = string(input);
        h = hash_func(input);
        if (loading) {
            if (!strcmp(input, "XXXXXX")) {
                loading = false;
                continue;
            }
            hash_table[h].push_back(s);
        } else {
            if (!strcmp(input, "XXXXXX")) {
                break;
            }
            if (hash_table[h].size()) {
                sort(hash_table[h].begin(), hash_table[h].end());
                for (int i = 0; i < hash_table[h].size(); ++i) {
                    puts(hash_table[h][i].c_str());
                }
            } else {
                puts("NOT A VALID WORD");
            }
            puts("******");
        }
    }
    return 0;
}

string hash_func(char *input) {
    map<char, int> m;
    char number[2];
    string result;
    for (int i = 0; i < strlen(input); ++i) {
        m[input[i]] += 1;
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        sprintf(number, "%d", m[c]);
        result.append(number);
    }
    return result;
}
