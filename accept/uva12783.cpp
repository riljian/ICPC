/* cut-edge, bridge */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <utility>
using namespace std;
#define MAXN 1005

struct Edge {
	int to;
	int next;
} edge[MAXN * MAXN];

int graph[MAXN];
int cnt_edge;
int low[MAXN];
int dfn[MAXN];
int cnt_dfn;
set<pair<int, int> > ans;

void init_graph() {
	memset(graph, -1, sizeof(graph));
	cnt_edge = 0;
}

void push_edge(int s, int t) {
	edge[cnt_edge].to = t;
	edge[cnt_edge].next = graph[s];
	graph[s] = cnt_edge;
	++cnt_edge;
}

void dfs(int p, int n) {
	int s, t;
	low[n] = dfn[n] = ++cnt_dfn;
	for (int e = graph[n]; ~e; e = edge[e].next) {
		if (!dfn[edge[e].to]) {
			dfs(n, edge[e].to);
			low[n] = min(low[n], low[edge[e].to]);
			if (low[edge[e].to] > dfn[n]) {
				s = edge[e].to;
				t = n;
				if (s > t) {
					swap(s, t);
				}
				ans.insert(make_pair(s, t));
			}
		} else if (edge[e].to != p) {
			low[n] = min(low[n], low[edge[e].to]);
		}
	}
}

void init() {
	init_graph();
	cnt_dfn = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	ans.clear();
}

int main() {
	int n, m, s, t;
	while (~scanf("%d %d", &n, &m) && (n + m)) {
		init();
		for (int i = 0; i < m; ++i) {
			scanf("%d %d", &s, &t);
			push_edge(s, t);
			push_edge(t, s);
		}
		for (int i = 0; i < n; ++i) {
			if (!dfn[i]) {
				dfs(-1, i);
			}
		}
		printf("%lu", ans.size());
		for (set<pair<int, int> >::iterator it = ans.begin(); it != ans.end(); ++it) {
			printf(" %d %d", it->first, it->second);
		}
		puts("");
	}
	return 0;
}
