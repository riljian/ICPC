/* strongly connected component, Tarjan, SCC */
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
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
int ans;
bool in_stack[MAXN];
map<string, int> name2num;
vector<int> stack;

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
		do {
			top = stack.back();
			stack.pop_back();
			in_stack[top] = false;
		} while (top != n);
		++ans;
	}
}

void init() {
	init_graph();
	name2num.clear();
	stack.clear();
	ans = cnt_dfn = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(in_stack, false, sizeof(in_stack));
}

int main() {
	string person1, person2;
	char surname[15], firstname[15];
	int p, t;
	while (scanf("%d %d\n", &p, &t) && (p + t)) {
		init();
		for (int i = 0; i < p; ++i) {
			scanf("%15[^,], %s\n", surname, firstname);
			person1 = surname;
			person1 += firstname;
			name2num[person1] = i;
		}
		for (int i = 0; i < t; ++i) {
			scanf("%15[^,], %s\n", surname, firstname);
			person1 = surname;
			person1 += firstname;
			scanf("%15[^,], %s\n", surname, firstname);
			person2 = surname;
			person2 += firstname;
			push_edge(name2num[person1], name2num[person2]);
		}
		for (int i = 0; i < p; ++i) {
			if (!dfn[i]) {
				dfs(i);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
