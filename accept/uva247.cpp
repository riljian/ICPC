/* strongly connected component, Tarjan, SCC */
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
#define MAXP 30
#define MAXL 30

int dfn_cnt, dfn[MAXP], low[MAXP];
bool visited[MAXP], in_sta[MAXP], graph[MAXP][MAXP];
map<int, string> id_name_t;
stack<int> sta;
void init_tarjan();
void tarjan(int);

int main() {
    int m, n, name_cnt, case_cnt = 0;
    char p1[MAXL], p2[MAXL];
    map<string, int> name_id_t;
    while (~scanf("%d %d", &m, &n) && m) {
        if (case_cnt) {
            puts("");
        }
        printf("Calling circles for data set %d:\n", ++case_cnt);
        init_tarjan();
        name_id_t.clear();
        id_name_t.clear();
        memset(graph, false, sizeof(graph));
        name_cnt = 0;
        while (n--) {
            scanf("%s %s", p1, p2);
            if (name_id_t.find(p1) == name_id_t.end()) {
                id_name_t[name_cnt] = p1;
                name_id_t[p1] = name_cnt++;
            }
            if (name_id_t.find(p2) == name_id_t.end()) {
                id_name_t[name_cnt] = p2;
                name_id_t[p2] = name_cnt++;
            }
            graph[name_id_t[p1]][name_id_t[p2]] = true;
        }
        for (int i = 0; i < m; ++i) {
            if (!visited[i]) {
                tarjan(i);
            }
        }
    }
    return 0;
}

void init_tarjan() {
    dfn_cnt = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(visited, false, sizeof(visited));
    memset(in_sta, false, sizeof(in_sta));
    while (!sta.empty()) {
        sta.pop();
    }
}

void tarjan(int n) {
    low[n] = dfn[n] = ++dfn_cnt;
    sta.push(n);
    visited[n] = in_sta[n] = true;
    for (int i = 0; i < MAXP; ++i) {
        if (graph[n][i]) {
            if (!dfn[i]) {
                tarjan(i);
                low[n] = min(low[n], low[i]);
            } else if (in_sta[i]) {
                low[n] = min(low[n], dfn[i]);
            }
        }
    }
    if (low[n] == dfn[n]) {
        while (sta.top() != n) {
            printf("%s, ", id_name_t[sta.top()].c_str());
            in_sta[sta.top()] = false;
            sta.pop();
        }
        printf("%s\n", id_name_t[sta.top()].c_str());
        in_sta[sta.top()] = false;
        sta.pop();
    }
}
