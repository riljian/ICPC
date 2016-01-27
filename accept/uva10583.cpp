/* disjoin set */
#include <cstdio>
#include <set>
using namespace std;
#define MAXN 50005

int findSet(int);
int unionSet(int, int);
int disjoin[MAXN];

int main() {
    int n, m, a, b, c = 0;
    set<int> s;
    while (scanf("%d %d", &n, &m) && (n + m)) {
        s.clear();
        for (int i = 1; i <= n; ++i) {
            disjoin[i] = i;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &a, &b);
            unionSet(a, b);
        }
        for (int i = 1; i <= n; ++i) {
            s.insert(findSet(i));
        }
        printf("Case %d: %lu\n", ++c, s.size());
    }
    return 0;
}

int findSet(int x) {
    if (x == disjoin[x]) {
        return x;
    } else {
        return disjoin[x] = findSet(disjoin[x]);
    }
}

int unionSet(int x, int y) {
    disjoin[findSet(x)] = disjoin[findSet(y)];
}
