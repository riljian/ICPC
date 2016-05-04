/* strongly connected component, Tarjan, SCC */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 2005

struct Edge {
	int to;
	int next;
} edge[MAXN * MAXN / 2];

int graph[MAXN];
int cnt_edge;
int low[MAXN];
int dfn[MAXN];
int cnt_dfn;
int ans;
bool in_stack[MAXN];
int ptr_stack;
int stack[MAXN];

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

void dfs(int n) {
	int top;
	low[n] = dfn[n] = ++cnt_dfn;
	stack[ptr_stack] = n;
	++ptr_stack;
	in_stack[n] = true;
	for (int e = graph[n]; ~e; e = edge[e].next) {
		if (!dfn[edge[e].to]) {
			dfs(edge[e].to);
			low[n] = min(low[n], low[edge[e].to]);
		} else if (in_stack[edge[e].to]) {
			low[n] = min(low[n], dfn[edge[e].to]);
		}
	}
	if (low[n] == dfn[n]) {
		do {
			top = stack[--ptr_stack];
			in_stack[top] = false;
		} while (top != n);
		++ans;
	}
}

void init() {
	init_graph();
	ptr_stack = 0;
	ans = cnt_dfn = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(in_stack, false, sizeof(in_stack));
}

int main() {
	int n, m, v, w, p;
	while (scanf("%d %d", &n, &m) && (n + m)) {
		init();
		for (int i = 0; i < m; ++i) {
			scanf("%d %d %d", &v, &w, &p);
			push_edge(v, w);
			if (p == 2) {
				push_edge(w, v);
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (!dfn[i]) {
				dfs(i);
			}
		}
		printf("%d\n", ans == 1);
	}
	return 0;
}
