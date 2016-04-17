/* disjoin set */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAXN 105

struct Ring {
    float x, y, r;
} rings[MAXN];

int ds[MAXN], set_size[MAXN];

int find_set(int);
void join_set(int, int);
bool ring_inter(int, int);

int main() {
    int n, max_set;
    while (~scanf("%d", &n) && ~n) {
        for (int i = 0; i < n; ++i) {
            ds[i] = i;
            scanf("%f %f %f", &rings[i].x, &rings[i].y, &rings[i].r);
            for (int j = 0; j < i; ++j) {
                if (ring_inter(i, j)) {
                    join_set(i, j);
                }
            }
        }
        memset(set_size, 0, sizeof(set_size));
        for (int i = 0; i < n; ++i) {
            set_size[find_set(i)]++;
        }
        max_set = 0;
        for (int i = 0; i < n; ++i) {
            max_set = max(max_set, set_size[i]);
        }
        if (max_set == 1) {
            puts("The largest component contains 1 ring.");
        } else {
            printf("The largest component contains %d rings.\n", max_set);
        }
    }
    return 0;
}

bool ring_inter(int m, int n) {
    float dis = 0.0;
    dis += pow(rings[m].x - rings[n].x, 2.0);
    dis += pow(rings[m].y - rings[n].y, 2.0);
    dis = sqrt(dis);
    if (dis <= rings[m].r + rings[n].r && dis >= abs(rings[m].r - rings[n].r)) {
        return true;
    } else {
        return false;
    }
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
