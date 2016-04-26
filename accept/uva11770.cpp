/* strongly connected component, tarjan, SCC */
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
#define MAXN 10005
#define MAXE 100005

struct Edge {
	int to;
	int from;
	int next;
} edge[MAXE], redge[MAXE];

int graph[MAXN];
int rgraph[MAXN];
int cnt_edge;
int low[MAXN];
int dfn[MAXN];
int cnt_dfn;
int ans;
bool in_stack[MAXN];
int stack[MAXN];
int ptr_stack;
set<int> now_scc;

void init_graph() {
	memset(graph, -1, sizeof(graph));
	memset(rgraph, -1, sizeof(rgraph));
	cnt_edge = 0;
}

void push_edge(int s, int t) {
	edge[cnt_edge].to = t;
	edge[cnt_edge].next = graph[s];
	redge[cnt_edge].from = s;
	redge[cnt_edge].next = rgraph[t];
	graph[s] = cnt_edge;
	rgraph[t] = cnt_edge;
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
		now_scc.clear();
		int cnt_in_edge = 0;
		for (int i = ptr_stack - 1; i >= 0; --i) {
			now_scc.insert(stack[i]);
			if (stack[i] == n) {
				break;
			}
		}
		do {
			top = stack[--ptr_stack];
			in_stack[top] = false;
			for (int e = rgraph[top]; ~e; e = redge[e].next) {
				if (now_scc.find(redge[e].from) == now_scc.end()) {
					++cnt_in_edge;
				}
			}
		} while (top != n);
		if (!cnt_in_edge) {
			++ans;
		}
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
	int cases, n, m, s, t;
	scanf("%d", &cases);
	for (int c = 1; c <= cases; ++c) {
		init();
		scanf("%d %d", &n, &m);
		while (m--) {
			scanf("%d %d", &s, &t);
			push_edge(s, t);
		}
		for (int i = 1; i <= n; ++i) {
			if (!dfn[i]) {
				dfs(i);
			}
		}
		printf("Case %d: %d\n", c, ans);
	}
	return 0;
}
