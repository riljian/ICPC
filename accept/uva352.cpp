/* BFS, DFS */
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
#define MAXN 30

int main() {
    int n, c = 0, ans, top, nxt;
    char map[MAXN * MAXN];
    bool visited[MAXN * MAXN];
    stack<int> s;
    while (~scanf("%d\n", &n)) {
        for (int i = 0; i < n; ++i) {
            fgets(map + i * n, sizeof(map), stdin);
        }
        ans = 0;
        memset(visited, false, sizeof(visited));
        for (int k = 0; k < n * n; ++k) {
            if (map[k] == '1' && !visited[k]) {
                ++ans;
                s.push(k);
                while (!s.empty()) {
                    top = s.top();
                    s.pop();
                    visited[top] = true;
                    for (int i = -1; i <= 1; ++i) {
                        for (int j = -1; j <= 1; ++j) {
                            nxt = i * n + j + top;
                            if (nxt < 0 || nxt >= n * n ||
                                    (j == -1 && nxt / n != (nxt + 1) / n) ||
                                    (j == 1 && nxt / n != (nxt - 1) / n) ||
                                    visited[nxt] ||
                                    map[nxt] == '0') {
                                continue;
                            }
                            s.push(nxt);
                        }
                    }
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n", ++c, ans);
    }
    return 0;
}
