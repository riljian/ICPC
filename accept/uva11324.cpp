/* strongly connected component, Tarjan, SCC, DAG, directed acyclic graph, DP, dynamic programming */
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
#define MAXN 1005
#define MAXE 50005

struct Edge {
	int to;
	int next;
} edge[MAXE];

int graph[MAXN];
int cnt_edge;
int low[MAXN];
int dfn[MAXN];
int cnt_dfn;
bool in_stack[MAXN];
int ptr_stack;
int stack[MAXN];
int scc_no[MAXN];
int scc_num[MAXN];
int dp[MAXN];
set<int> scc_graph[MAXN];

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
	int top, cnt = 0;
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
			scc_no[top] = n;
			++cnt;
		} while (top != n);
		scc_num[n] = cnt;
		scc_graph[n].clear();
	}
}

void init() {
	init_graph();
	ptr_stack = 0;
	cnt_dfn = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(in_stack, false, sizeof(in_stack));
	memset(dp, 0, sizeof(dp));
}

int find_ans(int s) {
	int m = 0;
	if (dp[s]) {
		return dp[s];
	}
	for (set<int>::iterator it = scc_graph[s].begin(); it != scc_graph[s].end(); ++it) {
		m = max(m, find_ans(*it));
	}
	return dp[s] = m + scc_num[s];
}

int main() {
	int cases, n, m, s, t, ans;
	scanf("%d", &cases);
	while (cases--) {
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
		for (int i = 1; i <= n; ++i) {
			for (int e = graph[i]; ~e; e = edge[e].next) {
				if (scc_no[i] != scc_no[edge[e].to]) {
					scc_graph[scc_no[i]].insert(scc_no[edge[e].to]);
				}
			}
		}
		ans = 0;
		for (int i = 1; i <= n; ++i) {
			ans = max(ans, find_ans(scc_no[i]));
		}
		printf("%d\n", ans);
	}
	return 0;
}
