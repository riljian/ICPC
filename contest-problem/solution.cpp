/* strongly connected component, SCC, shortest path, SPFA, negative ring */
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN 1000
#define MAXM 2000
#define INF 0x3f3f3f3f

struct Edge {
    int to, wt, nxt;
} edge_f[MAXM], edge_b[MAXM];

int graph_f[MAXN], graph_b[MAXN], edge_f_cnt, edge_b_cnt;
int sta[MAXN], in_sta[MAXN], sta_cnt;
int dfn[MAXN], dfn_cnt;
int low[MAXN];
int set[MAXN];
int sp[MAXN];
bool visited[MAXN];
bool possible;
queue<int> que;
int q_cnt[MAXN], in_que[MAXN];

void init();
void dfs(int); // mark nodes which the negative ring could arrive
int find_set(int);
void join_set(int, int);
void push_edge(int, int, int);
bool spfa(int); // return true if find a negative ring
void scc(int);

int main() {
    int cases, n, m, a, b, w;
    scanf("%d", &cases);
    for (int c = 1; c <= cases; ++c) {
        init();
        scanf("%d%d", &n, &m);
        while (m--) {
            scanf("%d%d%d", &a, &b, &w);
            push_edge(a, b, w);
        }
        for (int i = 0; i < n; ++i) {
            if (!dfn[i]) {
                scc(i);
            }
        }
        printf("Case %d:", c);
        if (possible) {
            for (int i = 0; i < n; ++i) {
                if (visited[i]) {
                    printf(" %d", i);
                }
            }
            puts("");
        } else {
            puts(" impossible");
        }
    }
    return 0;
}

void init() {
    dfn_cnt = edge_f_cnt = edge_b_cnt = 0;
    memset(graph_f, -1, sizeof(graph_f));
    memset(graph_b, -1, sizeof(graph_b));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(q_cnt, 0, sizeof(q_cnt));
    for (int i = 0; i < MAXN; ++i) {
        set[i] = i;
    }
    memset(visited, false, sizeof(visited));
    possible = false;
}

void push_edge(int s, int t, int w) {
    edge_f[edge_f_cnt].to = t;
    edge_f[edge_f_cnt].wt = w;
    edge_f[edge_f_cnt].nxt = graph_f[s];
    graph_f[s] = edge_f_cnt++;
    edge_b[edge_b_cnt].to = s;
    edge_b[edge_b_cnt].wt = w;
    edge_b[edge_b_cnt].nxt = graph_b[t];
    graph_b[t] = edge_b_cnt++;
}

int find_set(int n) {
    if (n == set[n]) {
        return n;
    } else {
        return set[n] = find_set(set[n]);
    }
}

void join_set(int a, int b) {
    set[find_set(a)] = set[find_set(b)];
}

bool spfa(int n, int set_size) {
    int front;
    while (!que.empty()) {
        in_que[que.front()] = false;
        que.pop();
    }
    que.push(n);
    in_que[n] = true;
    q_cnt[n]++;
    sp[n] = 0;
    while (!que.empty()) {
        front = que.front();
        que.pop();
        in_que[front] = false;
        for (int e = graph_f[front]; ~e; e = edge_f[e].nxt) {
            if (n == find_set(edge_f[e].to)) {
                if (sp[edge_f[e].to] > sp[front] + edge_f[e].wt) {
                    sp[edge_f[e].to] = sp[front] + edge_f[e].wt;
                    if (!in_que[edge_f[e].to]) {
                        que.push(edge_f[e].to);
                        in_que[edge_f[e].to] = true;
                        q_cnt[edge_f[e].to]++;
                        if (q_cnt[edge_f[e].to] == set_size) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

void dfs(int n) {
    visited[n] = true;
    for (int e = graph_b[n]; ~e; e = edge_b[e].nxt) {
        if (!visited[edge_b[e].to]) {
            dfs(edge_b[e].to);
        }
    }
}

void scc(int n) {
    dfn[n] = low[n] = ++dfn_cnt;
    sta[sta_cnt++] = n;
    in_sta[n] = true;
    for (int e = graph_f[n]; ~e; e = edge_f[e].nxt) {
        if (!dfn[edge_f[e].to]) {
            scc(edge_f[e].to);
            low[n] = min(low[n], low[edge_f[e].to]);
        } else if (in_sta[edge_f[e].to]) {
            low[n] = min(low[n], dfn[edge_f[e].to]);
        }
    }
    if (dfn[n] == low[n]) {
        int top, set_size = 0;
        do {
            top = sta[--sta_cnt];
            in_sta[top] = false;
            join_set(top, n);
            ++set_size;
            sp[top] = INF;
        } while (top != n);
        if (spfa(n, set_size)) {
            possible = true;
            dfs(n);
        }
    }
}
