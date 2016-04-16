/* disjoin set */
#include <cstdio>
using namespace std;
#define MAXN 100000

int ds[MAXN];

int find_set(int);
void join_set(int, int);

int main() {
    int cases, n, a, b, ans[2];
    char c;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        ans[0] = ans[1] = 0;
        for (int i = 1; i <= n; ++i) {
            ds[i] = i;
        }
        while (true) {
            getchar();
            c = getchar();
            if (c != 'c' && c != 'q') {
                break;
            }
            scanf("%d %d", &a, &b);
            if (c == 'c') {
                join_set(a, b);
            } else {
                if (find_set(a) == find_set(b)) {
                    ans[0]++;
                } else {
                    ans[1]++;
                }
            }
        }
        printf("%d,%d\n", ans[0], ans[1]);
        if (cases) {
            puts("");
        }
    }
    return 0;
}

int find_set(int n) {
    if (ds[n] == n) {
        return n;
    } else {
        return ds[n] = find_set(ds[n]);
    }
}

void join_set(int n, int m) {
    ds[find_set(n)] = ds[find_set(m)];
}
