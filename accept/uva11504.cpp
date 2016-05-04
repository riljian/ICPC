/* strongly connected component, Tarjan, SCC */
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
#define MAXN 1000005
#define MAXE 1000005

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
set<int> now_scc;
vector<int> stack;

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
	stack.push_back(n);
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
		for (vector<int>::reverse_iterator it = stack.rbegin(); it != stack.rend(); ++it) {
			now_scc.insert(*it);
			if (*it == n) {
				break;
			}
		}
		do {
			top = stack.back();
			stack.pop_back();
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
	stack.clear();
	ans = cnt_dfn = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(in_stack, false, sizeof(in_stack));
}

int main() {
	int cases, n, m, s, t;
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
		printf("%d\n", ans);
	}
	return 0;
}
