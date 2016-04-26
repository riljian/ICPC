/* implement */
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXR 10005

int main() {
    int m, n, r, t;
    vector<pair<int, int> > matrix[MAXR];
    vector<int> col;
    while (~scanf("%d %d", &m, &n)) {
        for (int i = 1; i <= n; ++i) {
            matrix[i].clear();
        }
        for (int i = 1; i <= m; ++i) {
            col.clear();
            scanf("%d", &r);
            for (int j = 0; j < r; ++j) {
                scanf("%d", &t);
                col.push_back(t);
            }
            for (int j = 0; j < r; ++j) {
                scanf("%d", &t);
                matrix[col[j]].push_back(make_pair(i, t));
            }
        }
        printf("%d %d\n", n, m);
        for (int i = 1; i <= n; ++i) {
            sort(matrix[i].begin(), matrix[i].end());
            printf("%lu", matrix[i].size());
            for (int j = 0; j < matrix[i].size(); ++j) {
                printf(" %d", matrix[i][j].first);
            }
            puts("");
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (j) {
                    putchar(' ');
                }
                printf("%d", matrix[i][j].second);
            }
            puts("");
        }
    }
    return 0;
}
