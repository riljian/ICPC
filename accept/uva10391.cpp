#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <map>
using namespace std;
#define MAXL 1000

int main() {
    char word[MAXL];
    string s;
    map<string, bool> dict;
    while (~scanf("%s", word)) {
        dict[string(word)] = true;
    }
    for (map<string, bool>::iterator it = dict.begin(); it != dict.end(); ++it) {
        s = it->first;
        for (int i = 1; i < s.length(); ++i) {
            if (dict.find(s.substr(0, i)) != dict.end() &&
                    dict.find(s.substr(i, s.length() - i)) != dict.end()) {
                puts(s.c_str());
                break;
            }
        }
    }
    return 0;
}
