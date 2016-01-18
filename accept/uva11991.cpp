/* hash table */
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int main() {
    int m, n, k, v, t;
    map<int, vector<int> > bst;
    while (~scanf("%d %d", &n, &m)) {
        bst.clear();
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &t);
            bst[t].push_back(i);
        }
        while (m--) {
            scanf("%d %d", &k, &v);
            if (k > bst[v].size()) {
                puts("0");
            } else {
                printf("%d\n", bst[v][k - 1]);
            }
        }
    }
    return 0;
}
