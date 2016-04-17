/* disjoin set, planar graph */
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
#define MAXN 60

int ds[MAXN];

int find_set(int);
void join_set(int, int);

int main() {
    int n, e, u;
    char a, b;
    set<int> c;
    while (~scanf("%d %d", &n, &e)) {
        memset(ds, -1, sizeof(ds));
        c.clear();
        u = n;
        for (int i = 0; i < e; ++i) {
            getchar();
            scanf("%c %c", &a, &b);
            if (ds[a - 'A'] == -1) {
                ds[a - 'A'] = a - 'A';
                --u;
            }
            if (ds[b - 'A'] == -1) {
                ds[b - 'A'] = b - 'A';
                --u;
            }
            join_set(a - 'A', b - 'A');
        }
        for (int i = 0; i < MAXN; ++i) {
            if (find_set(i) != -1) {
                c.insert(find_set(i));
            }
        }
        printf("%d\n", e + (int) c.size() + 1 + u - n);
    }
    return 0;
}

int find_set(int n) {
    if (n == ds[n] || ds[n] == -1) {
        return ds[n];
    } else {
        return ds[n] = find_set(ds[n]);
    }
}

void join_set(int n, int m) {
    ds[find_set(n)] = ds[find_set(m)];
}
