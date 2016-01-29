/* stack */
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
#define MAXL 130

int main() {
    int n;
    char input[MAXL];
    bool yes;
    scanf("%d\n", &n);
    stack<char> s;
    while (n--) {
        fgets(input, sizeof(input), stdin);
        while (!s.empty()) {
            s.pop();
        }
        yes = true;
        for (int i = 0; yes && i < strlen(input) - 1; ++i) {
            if (!s.empty() &&
                    ((input[i] == ']' && s.top() == '[') ||
                    (input[i] == ')' && s.top() == '('))) {
                s.pop();
            } else if (input[i] == '[' || input[i] == '(') {
                s.push(input[i]);
            } else {
                yes = false;
            }
        }
        yes = yes && s.empty();
        puts(yes ? "Yes" : "No");
    }
    return 0;
}
