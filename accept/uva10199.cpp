/* cut-vertex, articulation */
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <cstring>
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
map<string, int> city2num;
map<int, string> num2city;
set<string> set_city;

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
		set_city.insert(num2city[n]);
	}
}

void init() {
	init_graph();
	cnt_dfn = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	city2num.clear();
	num2city.clear();
	set_city.clear();
}

int main() {
	int n, m, s, t, cnt_case = 0;
	string city1, city2;
	while (cin >> n && n) {
		init();
		for (int i = 1; i <= n; ++i) {
			cin >> city1;
			city2num[city1] = i;
			num2city[i] = city1;
		}
		cin >> m;
		while (m--) {
			cin >> city1 >> city2;
			s = city2num[city1];
			t = city2num[city2];
			push_edge(s, t);
			push_edge(t, s);
		}
		for (int i = 1; i <= n; ++i) {
			if (!dfn[i]) {
				dfs(-1, i);
			}
		}
		if (cnt_case) {
			cout << endl;
		}
		cout << "City map #" << ++cnt_case << ": " << set_city.size() << " camera(s) found" << endl;
		for (set<string>::iterator it = set_city.begin(); it != set_city.end(); ++it) {
			cout << *it << endl;
		}
	}
	return 0;
}
