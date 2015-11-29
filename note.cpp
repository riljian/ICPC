// cut vertex
void init() {
	init_graph();
	ans = cnt_dfn = 0; // ans: number of cut vertex
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
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
			low[n] = min(low[n], dfn[edge[e].to]); // note #1
		}
	}
	if ((child > 1 || p != -1) && cut_vertex) {
		++ans;
	}
}

for (int i = 1; i <= n; ++i) { // for dfs forest
	if (!dfn[i]) {
		dfs(-1, i);
	}
}

// note #1:
// low[n] = min(low[n], low[edge[e].to]);
// wrong case:
// 1 - 2, 2 - 3, 2 - 5, 3 - 4, 3 - 6, 3 - 5, 4 - 6

// cut edge (bridge)
void dfs(int p, int n) {
	int s, t;
	low[n] = dfn[n] = ++cnt_dfn;
	for (int e = graph[n]; ~e; e = edge[e].next) {
		if (!dfn[edge[e].to]) {
			dfs(n, edge[e].to);
			low[n] = min(low[n], low[edge[e].to]);
			if (low[edge[e].to] > dfn[n]) {
				// edge[e].to - n is bridge
			}
		} else if (edge[e].to != p) {
			low[n] = min(low[n], low[edge[e].to]);
		}
	}
}

// strongly connected component
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
			top = stack.back(); // top is one of this strongly connected component's element
			stack.pop_back();
			in_stack[top] = false;
		} while (top != n);
		++ans;
	}
}
