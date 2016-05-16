/* minimum spanning tree */
#include <cstdio>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
#define MAXN 505

int ds[MAXN];
vector<pair<double, double> > nodes;

int find_set(int);
void join_set(int, int);
double dis(pair<int, int>);
bool cmp(pair<int, int>, pair<int, int>);

int main() {
    int cases, n, m;
    double a, b, ans;
    scanf("%d", &cases);
    vector<pair<int, int> > edges;
    while (cases--) {
        scanf("%d%d", &m, &n);
        nodes.clear();
        edges.clear();
        ans = 0;
        m = n - m;
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf", &a, &b);
            nodes.push_back(make_pair(a, b));
            ds[i] = i;
            for (int j = i + 1; j < n; ++j) {
                edges.push_back(make_pair(i, j));
            }
        }
        sort(edges.begin(), edges.end(), cmp);
        for (int i = 0; i < edges.size() && m; ++i) {
            if (find_set(edges[i].first) != find_set(edges[i].second)) {
                join_set(edges[i].first, edges[i].second);
                ans = max(ans, dis(edges[i]));
                --m;
            }
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}

int find_set(int n) {
    if (n == ds[n]) {
        return n;
    }
    return ds[n] = find_set(ds[n]);
}

void join_set(int m, int n) {
    ds[find_set(m)] = ds[find_set(n)];
}

double dis(pair<int, int> e) {
    double sum = 0;
    sum += pow(nodes[e.first].first - nodes[e.second].first, 2);
    sum += pow(nodes[e.first].second - nodes[e.second].second, 2);
    return sqrt(sum);
}

bool cmp(pair<int, int> l, pair<int, int> r) {
    return dis(l) < dis(r);
}
