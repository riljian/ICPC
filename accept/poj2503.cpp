/* map */
#include <cstdio>
#include <string>
#include <map>
using namespace std;
#define MAXL 20

int main() {
    bool loading = true;
    char line[MAXL * 2], word1[MAXL], word2[MAXL];
    string s;
    map<string, string> dict;
    while (fgets(line, sizeof(line), stdin)) {
        if (loading) {
            if (sscanf(line, "%s %s", word1, word2) == 2) {
                dict[string(word2)] = string(word1);
            } else {
                loading = false;
            }
        } else {
            sscanf(line, "%s", word1);
            s = dict[string(word1)];
            if (s.empty()) {
                puts("eh");
            } else {
                puts(s.c_str());
            }
        }
    }
    return 0;
}
