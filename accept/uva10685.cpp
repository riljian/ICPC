/* disjoin set */
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
#define MAXN 5005
#define MAXL 35

int ds[MAXN], set_size[MAXN];

int find_set(int);
void join_set(int, int);

int main() {
    int n, r, ans;
    char a[MAXL], b[MAXL];
    map<string, int> m;
    while (~scanf("%d %d", &n, &r) && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%s", a);
            m[a] = i;
            ds[i] = i;
        }
        while (r--) {
            scanf("%s %s", a, b);
            join_set(m[a], m[b]);
        }
        memset(set_size, 0, sizeof(set_size));
        for (int i = 0; i < n; ++i) {
            set_size[find_set(i)]++;
        }
        ans = 1;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, set_size[i]);
        }
        printf("%d\n", ans);
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

void join_set(int m, int n) {
    ds[find_set(m)] = ds[find_set(n)];
}
