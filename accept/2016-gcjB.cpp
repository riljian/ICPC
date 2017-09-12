#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 105

int main() {
    int cases, ans, n;
    char line[MAXN];
    bool first;
    scanf("%d\n", &cases);
    for (int c = 1; c <= cases; ++c) {
        fgets(line, sizeof(line), stdin);
        ans = n = 0;
        for (int i = 1; i < strlen(line) - 1; ++i) {
            if (line[i] != line[n]) {
                line[++n] = line[i];
            }
        }
        line[++n] = 0;
        first = true;
        for (int i = 0; i < n; ++i) {
            if (line[i] == '-') {
                ans += first ? 1 : 2;
            }
            first = false;
        }
        printf("Case #%d: %d\n", c, ans);
    }
    return 0;
}
