/* cut vertex, articulation */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 105

struct Edge {
	int to;
	int next;
} edge[MAXN * MAXN];

int graph[MAXN];
int cnt_edge;
int low[MAXN];
int dfn[MAXN];
int cnt_dfn;
int ans;

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
	bool cut_vertex = false;
	int child = 0;
	low[n] = dfn[n] = ++cnt_dfn;
	for (int e = graph[n]; ~e; e = edge[e].next) {
		if (!dfn[edge[e].to]) {
			dfs(n, edge[e].to);
			low[n] = min(low[n], low[edge[e].to]);
			if (low[edge[e].to] >= dfn[n]) {
				cut_vertex = true;
			}
			++child;
		} else if (edge[e].to != p) {
			low[n] = min(low[n], dfn[edge[e].to]);
		}
	}
	if ((child > 1 || p != -1) && cut_vertex) {
		++ans;
	}
}

void init() {
	init_graph();
	ans = cnt_dfn = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
}

int main() {
	int s, t, n;
	char line[MAXN * 4], *number;
	while (scanf("%d\n", &n) && n) {
		init();
		do {
			fgets(line, sizeof(line), stdin);
			s = 0;
			for (number = strtok(line, " "); number != NULL; number = strtok(NULL, " ")) {
				if (s) {
					t = atoi(number);
					push_edge(s, t);
					push_edge(t, s);
				} else {
					s = atoi(number);
				}
			}
		} while (s);
		dfs(-1, 1);
		printf("%d\n", ans);
	}
	return 0;
}
