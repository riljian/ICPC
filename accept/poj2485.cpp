/* minimum spanning tree */
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
using namespace std;
#define MAXN 505

int map[MAXN][MAXN], ds[MAXN];
bool cmp(pair<int, int>, pair<int, int>);
int find_set(int);
void join_set(int, int);

int main() {
    int cases, n, ans;
    vector<pair<int, int> > edges;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        ans = 0;
        edges.clear();
        memset(map, 0, sizeof(map));
        for (int i = 0; i < n; ++i) {
            ds[i] = i;
            for (int j = 0; j < n; ++j) {
                scanf("%d", &map[i][j]);
                if (i < j) {
                    edges.push_back(make_pair(i, j));
                }
            }
        }
        sort(edges.begin(), edges.end(), cmp);
        for (int i = 0; i < edges.size(); ++i) {
            if (find_set(edges[i].first) != find_set(edges[i].second)) {
                join_set(edges[i].first, edges[i].second);
                ans = max(ans, map[edges[i].first][edges[i].second]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

int find_set(int n) {
    if (ds[n] == n) {
        return n;
    }
    return ds[n] = find_set(ds[n]);
}

void join_set(int m, int n) {
    ds[find_set(m)] = ds[find_set(n)];
}

bool cmp(pair<int, int> l, pair<int, int> r) {
    return map[l.first][l.second] < map[r.first][r.second];
}
