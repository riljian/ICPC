#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
#define MAXL 35
#define MAXN 5005

int disjoin[MAXN];
int find(int);
void join(int, int);

int main() {
    int m, n, count[MAXN], ans;
    char ani1[MAXL], ani2[MAXL];
    map<string, int> dict;
    while (scanf("%d %d\n", &m, &n) && (m + n)) {
        dict.clear();
        memset(count, 0, sizeof(count));
        ans = 1;
        for (int i = 0; i < m; ++i) {
            scanf("%s", ani1);
            dict[string(ani1)] = i;
            disjoin[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%s %s", ani1, ani2);
            join(dict[string(ani1)], dict[string(ani2)]);
        }
        for (int i = 0; i < m; ++i) {
            count[find(i)]++;
        }
        for (int i = 0; i < m; ++i) {
            ans = max(ans, count[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}

int find(int x) {
    if (x == disjoin[x]) {
        return x;
    } else {
        return disjoin[x] = find(disjoin[x]);
    }
}

void join(int x, int y) {
    disjoin[find(x)] = disjoin[find(y)];
}
