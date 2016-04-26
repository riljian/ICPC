/* cut edge, bridge */
#include <cstdio>
#include <algorithm>
#include <cstring>
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
	low[n] = dfn[n] = ++cnt_dfn;
	for (int e = graph[n]; ~e; e = edge[e].next) {
		if (!dfn[edge[e].to]) {
			dfs(n, edge[e].to);
			low[n] = min(low[n], low[edge[e].to]);
			if (low[edge[e].to] > dfn[n]) {
				printf("%d %d\n", edge[e].to, n);
				printf("%d %d\n", n, edge[e].to);
			} else {
				printf("%d %d\n", n, edge[e].to);
			}
		} else if (edge[e].to != p) {
			low[n] = min(low[n], low[edge[e].to]);
			if (dfn[edge[e].to] < dfn[n]) {
				printf("%d %d\n", n, edge[e].to);
			}
		}
	}
}

void init() {
	init_graph();
	cnt_dfn = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
}

int main() {
	int n, m, s, t, cnt = 0;
	while (scanf("%d %d", &m, &n) && (m + n)) {
		init();
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &s, &t);
			push_edge(s, t);
			push_edge(t, s);
		}
		printf("%d\n\n", ++cnt);
		for (int i = 1; i <= m; ++i) {
			if (!dfn[i]) {
				dfs(-1, i);
			}
		}
		puts("#");
	}
	return 0;
}
