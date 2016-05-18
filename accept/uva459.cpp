/* disjoin set */
#include <cstdio>
using namespace std;
#define MAXN 30
#define MAXL 4

int ds[MAXN], ans;
int find_set(int);
void join_set(int, int);

int main() {
    int n, m;
    char str[MAXL];
    scanf("%d", &n);
    while (n--) {
        scanf("%s", str);
        getchar();
        ans = m = str[0] - 'A' + 1;
        for (int i = 0; i < m; ++i) {
            ds[i] = i;
        }
        while (fgets(str, MAXL, stdin) && str[0] != '\n') {
            join_set(str[0] - 'A', str[1] - 'A');
        }
        printf("%d\n", ans);
        if (n) {
            puts("");
        }
    }
    return 0;
}

int find_set(int n) {
    if (ds[n] == n) {
        return n;
    }
    return ds[n] = find_set(ds[n]);
}

void join_set(int m, int n) {
    int l = find_set(m), r = find_set(n);
    ds[l] = ds[r];
    if (l != r) {
        --ans;
    }
}
