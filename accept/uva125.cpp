/* negative ring, Floyd-Warshall */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 30

int main() {
    int n, m, c = 0, a, b;
    int g[MAXN][MAXN];
    while (~scanf("%d", &m)) {
        memset(g, 0, sizeof(g));
        n = 0;
        while (m--) {
            scanf("%d%d", &a, &b);
            n = max(n, max(a, b));
            ++g[a][b];
        }
        ++n;
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    g[i][j] += g[i][k] * g[k][j];
                }
            }
        }
        for (int k = 0; k < n; ++k) {
            if (g[k][k]) {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (g[i][k] && g[k][j]) {
                            g[i][j] = -1;
                        }
                    }
                }
            }
        }
        printf("matrix for city %d\n", c++);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j) {
                    putchar(' ');
                }
                printf("%d", g[i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}
