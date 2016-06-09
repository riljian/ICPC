/* backtrack */
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 50
#define ANSL 6

int ans[ANSL];
void backtrack(int [], int, int, int);

int main() {
    int n, in[MAXN], first = 1;
    while (scanf("%d", &n) && n) {
        if (!first) {
            putchar('\n');
        }
        first = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &in[i]);
        }
        sort(in, in + n);
        backtrack(in, 0, ANSL, n);
    }
    return 0;
}

void backtrack(int in[MAXN], int from, int remain, int n) {
    if (!remain) {
        for (int i = 0; i < ANSL; ++i) {
            printf("%d", ans[i]);
            if (i == ANSL - 1) {
                putchar('\n');
            } else {
                putchar(' ');
            }
        }
        return;
    }
    for (int i = from; i <= n - remain; ++i) {
        ans[ANSL - remain] = in[i];
        backtrack(in, i + 1, remain - 1, n);
    }
}
