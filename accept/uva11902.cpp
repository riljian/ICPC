/* depth first search, dominator, DFS */
#include <cstdio>
#include <set>
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
bool ans[MAXN];
bool visited[MAXN];

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

void dfs(int s, int x) {
	if (s != x) {
		visited[s] = true;
		for (int e = graph[s]; ~e; e = edge[e].next) {
			if (!visited[edge[e].to]) {
				dfs(edge[e].to, x);
			}
		}
	}

}

int main() {
	int n, t, cases;
	char hr[MAXN * 2], output[MAXN * 2];
	bool original[MAXN];
	scanf("%d", &cases);
	for (int c = 1; c <= cases; ++c) {
		scanf("%d", &n);
		init_graph();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &t);
				if (t) {
					push_edge(i, j);
				}
			}
		}
		printf("Case %d:\n", c);
		for (int i = 0; i < 2 * n + 1; ++i) {
			if (i == 0 || i == 2 * n) {
				hr[i] = '+';
			} else {
				hr[i] = '-';
			}
		}
		hr[2 * n + 1] = '\0';
		memset(visited, false, sizeof(visited));
		dfs(0, -1);
		memcpy(original, visited, n * sizeof(bool));
		for (int i = 0; i < n; ++i) {
			memset(visited, false, sizeof(visited));
			dfs(0, i);
			for (int j = 0; j < n; ++j) {
				ans[j] = original[j] ^ visited[j];
			}
			if (!i) {
				puts(hr);
			}
			for (int j = 0; j < n; ++j) {
				output[2 * j] = '|';
				output[2 * j + 1] = ans[j] ? 'Y' : 'N';
			}
			output[2 * n] = '|';
			output[2 * n + 1] = '\0';
			puts(output);
			puts(hr);
		}
	}
	return 0;
}
