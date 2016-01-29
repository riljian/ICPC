/* Breadth-First-Search, bfs */
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN 35
#define DIRS 6

char dungeon[MAXN][MAXN][MAXN];
bool visited[MAXN][MAXN][MAXN];
int dir[DIRS][3] = {
    {1, 0, 0},
    {-1, 0, 0},
    {0, 1, 0},
    {0, -1, 0},
    {0, 0, 1},
    {0, 0, -1}
};
struct Pos {
    int x, y, z, d;
    Pos(int _x, int _y, int _z, int _d):
        x(_x), y(_y), z(_z), d(_d) {}
    Pos() {}
};

int main() {
    int l, r, c, ans;
    struct Pos now, nxt;
    queue<struct Pos> q;
    while (scanf("%d %d %d\n", &l, &r, &c) && (l + r + c)) {
        memset(dungeon, '#', sizeof(dungeon));
        memset(visited, false, sizeof(visited));
        ans = -1;
        while (!q.empty()) {
            q.pop();
        }
        for (int i = 1; i <= l; ++i) {
            for (int j = 1; j <= r; ++j) {
                fgets(dungeon[i][j] + 1, sizeof(dungeon), stdin);
                dungeon[i][j][c + 1] = '#';
                for (int k = 1; k <= c; ++k) {
                    if (dungeon[i][j][k] == 'S') {
                        q.push(Pos(i, j, k, 0));
                        visited[i][j][k] = true;
                    }
                }
            }
            getchar();
        }
        while (!q.empty() && ans == -1) {
            now = q.front();
            q.pop();
            nxt.d = now.d + 1;
            for (int i = 0; i < DIRS; ++i) {
                nxt.x = now.x + dir[i][0];
                nxt.y = now.y + dir[i][1];
                nxt.z = now.z + dir[i][2];
                if (dungeon[nxt.x][nxt.y][nxt.z] != '#' &&
                        !visited[nxt.x][nxt.y][nxt.z]) {
                    if (dungeon[nxt.x][nxt.y][nxt.z] == 'E') {
                        ans = nxt.d;
                        break;
                    }
                    q.push(nxt);
                    visited[nxt.x][nxt.y][nxt.z] = true;
                }
            }
        }
        if (~ans) {
            printf("Escaped in %d minute(s).\n", ans);
        } else {
            puts("Trapped!");
        }
    }
    return 0;
}
