/* implement */
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 1005

int main() {
    int n, m, cnt[MAXN][MAXN], c = 0;
    char map[MAXN][MAXN];
    while (~scanf("%d%d\n", &m, &n) && m) {
        if (c) {
            putchar('\n');
        }
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= m; ++i) {
            fgets(map[i] + 1, MAXN - 1, stdin);
            for (int j = 1; j <= n; ++j) {
                if (map[i][j] == '*') {
                    for (int k = i - 1; k <= i + 1; ++k) {
                        for (int l = j - 1; l <= j + 1; ++l) {
                            ++cnt[k][l];
                        }
                    }
                }
            }
        }
        printf("Field #%d:\n", ++c);
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (map[i][j] == '*') {
                    putchar('*');
                } else {
                    putchar('0' + cnt[i][j]);
                }
            }
            putchar('\n');
        }
    }
    return 0;
}
