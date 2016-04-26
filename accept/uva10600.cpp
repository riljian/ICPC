/* minimum spanning tree, MST */
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
#define MAXN 105
#define INF 0x3f3f3f3f

struct Edge {
    int s, t, w;
    bool operator<(const Edge &t) const {
        return w < t.w;
    }
} edge[MAXN * MAXN];
int ds[MAXN];

int find_set(int);
void join_set(int, int);
void init_ds(int);

int main() {
    int m, n, cases, a, b, c, sum, cnt, ans;
    set<int> s;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d%d", &n, &m);
        init_ds(n);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &edge[i].s, &edge[i].t, &edge[i].w);
        }
        sort(edge, edge + m);
        s.clear();
        sum = 0;
        for (int i = 0; s.size() < n - 1; ++i) {
            if (find_set(edge[i].s) != find_set(edge[i].t)) {
                s.insert(i);
                join_set(edge[i].s, edge[i].t);
                sum += edge[i].w;
            }
        }
        printf("%d", sum);
        ans = INF;
        for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
            sum = cnt = 0;
            init_ds(n);
            for (int i = 0; cnt < n - 1 && i < m; ++i) {
                if (i != *it && find_set(edge[i].s) != find_set(edge[i].t)) {
                    join_set(edge[i].s, edge[i].t);
                    sum += edge[i].w;
                    ++cnt;
                }
            }
            if (cnt == n - 1) {
                ans = min(ans, sum);
            }
        }
        printf(" %d\n", ans);
    }
    return 0;
}

void init_ds(int n) {
    for (int i = 1; i <= n; ++i) {
        ds[i] = i;
    }
}

int find_set(int n) {
    if (ds[n] == n) {
        return n;
    } else {
        return ds[n] = find_set(ds[n]);
    }
}

void join_set(int m, int n) {
    ds[find_set(m)] = ds[find_set(n)];
}
