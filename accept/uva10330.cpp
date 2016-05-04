/* maximum flow */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 105
#define INF 0x3f3f3f3f

struct Edge {
    int to, nxt;
} edge[MAXN * MAXN * 4];

int graph[MAXN * 2], edge_cnt;
int cap[MAXN * 2][MAXN * 2], flow[MAXN * 2][MAXN * 2];
int pa[MAXN * 2];
bool visited[MAXN * 2];

void init();
void push_edge(int, int, int);
int ford_fulkerson(int);
bool dfs(int, int, int);
int find_flow(int, int);

int main() {
    int n, m, a, b, c;
    while (~scanf("%d", &n)) {
        init();
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            push_edge(i + 1, i + n + 1, a);
        }
        scanf("%d", &m);
        while (m--) {
            scanf("%d%d%d", &a, &b, &c);
            push_edge(a + n, b, c);
        }
        scanf("%d%d", &a, &b);
        while (a--) {
            scanf("%d", &c);
            push_edge(0, c, INF);
        }
        while (b--) {
            scanf("%d", &c);
            push_edge(c + n, 2 * n + 1, INF);
        }
        printf("%d\n", ford_fulkerson(n * 2 + 2));
    }
    return 0;
}

void init() {
    edge_cnt = 0;
    memset(graph, -1, sizeof(graph));
    memset(cap, 0, sizeof(cap));
    memset(flow, 0, sizeof(flow));
}

void push_edge(int a, int b, int c) {
    edge[edge_cnt].to = b;
    edge[edge_cnt].nxt = graph[a];
    graph[a] = edge_cnt++;
    edge[edge_cnt].to = a;
    edge[edge_cnt].nxt = graph[b];
    graph[b] = edge_cnt++;
    cap[a][b] = c;
}

int ford_fulkerson(int n) {
    int ret = 0;

    while (true) {
        memset(visited, false, sizeof(visited));
        if (!dfs(0, n - 1, n)) {
            break;
        }
        ret += find_flow(0, n - 1);
    }

    return ret;
}

bool dfs(int cur, int ter, int n) {

    visited[cur] = true;

    if (cur == ter) {
        return true;
    }

    for (int e = graph[cur]; ~e; e = edge[e].nxt) {
        if (!visited[edge[e].to]) {
            if (cap[cur][edge[e].to] > flow[cur][edge[e].to] || flow[edge[e].to][cur]) {
                pa[edge[e].to] = cur;
                if (dfs(edge[e].to, ter, n)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int find_flow(int s, int t) {
    int pre, f = INF;

    for (int i = t; i != s; i = pa[i]) {
        pre = pa[i];
        if (cap[pre][i] > flow[pre][i]) {
            f = min(f, cap[pre][i] -flow[pre][i]);
        } else {
            f = min(f, flow[i][pre]);
        }
    }

    for (int i = t; i != s; i = pa[i]) {
        pre = pa[i];
        if (cap[pre][i] > flow[pre][i]) {
            flow[pre][i] += f;
        } else {
            flow[i][pre] -= f;
        }
    }

    return f;
}
