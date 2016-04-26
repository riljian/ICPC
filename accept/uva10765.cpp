/* cut edge, bridge */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 10005

struct Edge {
	int to;
	int next;
	bool usable;
} edge[MAXN * 10];

int graph[MAXN];
int cnt_edge;
int low[MAXN];
int dfn[MAXN];
int pigeon[MAXN];
int cnt_dfn;
int ans[MAXN];

void init_graph() {
	memset(graph, -1, sizeof(graph));
	cnt_edge = 0;
}

void push_edge(int s, int t) {
	edge[cnt_edge].to = t;
	edge[cnt_edge].next = graph[s];
	edge[cnt_edge].usable = true;
	graph[s] = cnt_edge;
	++cnt_edge;
}

void bridge(int p, int n) {
	low[n] = dfn[n] = ++cnt_dfn;
	for (int e = graph[n]; ~e; e = edge[e].next) {
		if (!dfn[edge[e].to]) {
			bridge(n, edge[e].to);
			low[n] = min(low[n], low[edge[e].to]);
			if (low[edge[e].to] > dfn[n]) {
				edge[e].usable = false;
				edge[e ^ 1].usable = false;
				++pigeon[n];
				++pigeon[edge[e].to];
			}
		} else if (edge[e].to != p) {
			low[n] = min(low[n], low[edge[e].to]);
		}
	}
}

void dfs(int s) {
	for (int e = graph[s]; ~e; e = edge[e].next) {
		if (edge[e].usable && !dfn[edge[e].to]) {
			dfn[edge[e].to] = 1;
			dfs(edge[e].to);
		}
	}
}

void init() {
	init_graph();
	cnt_dfn = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(pigeon, 0, sizeof(pigeon));
}

bool compare(int i, int j) {
	if (pigeon[i] != pigeon[j]) {
		return pigeon[i] > pigeon[j];
	} else {
		return i < j;
	}
}

int main() {
	int n, m, s, t;
	while (scanf("%d %d", &n, &m) && (m + n)) {
		init();
		while (scanf("%d %d", &s, &t) && s >= 0) {
			push_edge(s, t);
			push_edge(t, s);
		}
		bridge(-1, 0);
		memset(dfn, 0, sizeof(dfn));
		for (int i = 0; i < n; ++i) {
			if (!dfn[i]) {
				dfs(i);
			}
			pigeon[i] += dfn[i];
			ans[i] = i;
		}
		sort(ans, ans + n, compare);
		for (int i = 0; i < m; ++i) {
			if (i) {
				putchar('\n');
			}
			printf("%d %d", ans[i], pigeon[ans[i]]);
		}
		puts("\n");
	}
	return 0;
}
