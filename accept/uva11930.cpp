/* strongly connected component, line intersection, two satisfiability */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 1000
#define POS(x) ((x)*2)
#define NEG(x) ((x)*2+1)
#define P1 segment[a][0]
#define P2 segment[a][1]
#define P3 segment[b][0]
#define P4 segment[b][1]

struct Edge {
    int to, next;
} edge[MAXN * MAXN * 4];

int graph[MAXN * 2], ecnt;
long long segment[MAXN * 2][2][2];
int stack[MAXN * 2], scnt;
int low[MAXN * 2], dfn[MAXN * 2], dcnt, cpn[MAXN * 2], ccnt;
bool ins[MAXN * 2], ans;

void init();
void push_edge(int, int);
bool on_segment(long long[], long long[], long long[]);
bool intersect(int, int);
void scc(int);

int main() {
    int n;

    while (~scanf("%d", &n) && n) {
        init();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 4; ++j) {
                int nseg = 2 * i + j % 2, npoi = j / 2;
                scanf("%lld%lld", &segment[nseg][npoi][0], &segment[nseg][npoi][1]);
            }
            for (int j = 0; !intersect(POS(i), NEG(i)); ++j) {
                swap(segment[POS(i)][1][0], segment[NEG(i)][j][0]);
                swap(segment[POS(i)][1][1], segment[NEG(i)][j][1]);
            }
            for (int j = 0; j < i; ++j) {
                if (intersect(POS(j), POS(i))) {
                    push_edge(POS(j), NEG(i));
                    push_edge(POS(i), NEG(j));
                }
                if (intersect(POS(j), NEG(i))) {
                    push_edge(POS(j), POS(i));
                    push_edge(NEG(i), NEG(j));
                }
                if (intersect(NEG(j), POS(i))) {
                    push_edge(NEG(j), NEG(i));
                    push_edge(POS(i), POS(j));
                }
                if (intersect(NEG(j), NEG(i))) {
                    push_edge(NEG(j), POS(i));
                    push_edge(NEG(i), POS(j));
                }
            }
        }
        for (int i = 0; i < n * 2; ++i) {
            if (!dfn[i]) {
                scc(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (cpn[POS(i)] == cpn[NEG(i)]) {
                ans = false;
            }
        }
        puts(ans ? "YES" : "NO");
    }

    return 0;
}

void init() {
    memset(graph, -1, sizeof(graph));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    ccnt = dcnt = scnt = ecnt = 0;
    ans = true;
}

void push_edge(int a, int b) {
    edge[ecnt].to = b;
    edge[ecnt].next = graph[a];
    graph[a] = ecnt++;
}

bool on_segment(long long a[], long long b[], long long c[]) {
    if (min(a[0], b[0]) <= c[0] && c[0] <= max(a[0], b[0]) &&
            min(a[1], b[1]) <= c[1] && c[1] <= max(a[1], b[1])) {
        return true;
    } else {
        return false;
    }
}

bool intersect(int a, int b) {
    long long d1 = (P1[0] - P3[0]) * (P4[1] - P3[1]) - (P1[1] - P3[1]) * (P4[0] - P3[0]);
    long long d2 = (P2[0] - P3[0]) * (P4[1] - P3[1]) - (P2[1] - P3[1]) * (P4[0] - P3[0]);
    long long d3 = (P3[0] - P1[0]) * (P2[1] - P1[1]) - (P3[1] - P1[1]) * (P2[0] - P1[0]);
    long long d4 = (P4[0] - P1[0]) * (P2[1] - P1[1]) - (P4[1] - P1[1]) * (P2[0] - P1[0]);

    d1 = d1 == 0 ? 0 : (d1 > 0 ? 1 : -1);
    d2 = d2 == 0 ? 0 : (d2 > 0 ? 1 : -1);
    d3 = d3 == 0 ? 0 : (d3 > 0 ? 1 : -1);
    d4 = d4 == 0 ? 0 : (d4 > 0 ? 1 : -1);

    if (d1 * d2 < 0 && d3 * d4 < 0) {
        return true;
    }
    if (!d1 && on_segment(P3, P4, P1)) {
        return true;
    }
    if (!d2 && on_segment(P3, P4, P2)) {
        return true;
    }
    if (!d3 && on_segment(P1, P2, P3)) {
        return true;
    }
    if (!d4 && on_segment(P1, P2, P4)) {
        return true;
    }
    return false;
}

void scc(int n) {
    int top, to;

    low[n] = dfn[n] = ++dcnt;
    stack[scnt++] = n;
    ins[n] = true;
    for (int e = graph[n]; ~e; e = edge[e].next) {
        to = edge[e].to;
        if (!dfn[to]) {
            scc(to);
            low[n] = min(low[n], low[to]);
        } else if (ins[to]) {
            low[n] = min(low[n], dfn[to]);
        }
    }
    if (low[n] == dfn[n]) {
        ++ccnt;
        do {
            top = stack[--scnt];
            ins[top] = false;
            cpn[top] = ccnt;
        } while (top != n);
    }
}
