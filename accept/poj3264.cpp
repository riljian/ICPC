/* segment tree */
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 50005
#define MAXH 1000005

struct Node {
    int max, min, begin, end;
} node[1 << 17];
int s_max, s_min;

void build(int, int, int, int []);
int query(int, int, int);

int main() {
    int n, q, height[MAXN], a, b;
    scanf("%d %d", &n, &q);
    build(1, 1, n, height);
    while (q--) {
        s_max = -1;
        s_min = MAXH;
        scanf("%d %d", &a, &b);
        query(1, a, b);
        printf("%d\n", s_max - s_min);
    }
    return 0;
}

void build(int n, int b, int e, int height[]) {
    int mid = (b + e) / 2;
    node[n].begin = b, node[n].end = e;
    if (b < e) {
        build(n * 2, b, mid, height);
        build(n * 2 + 1, mid + 1, e, height);
        node[n].max = max(node[n * 2].max, node[n * 2 + 1].max);
        node[n].min = min(node[n * 2].min, node[n * 2 + 1].min);
    } else {
        scanf("%d", height + mid);
        node[n].max = node[n].min = height[b];
    }
}

int query(int n, int b, int e) {
    int mid = b + e;
    if (!(node[n].begin > e || node[n].end < b)) {
        if (node[n].begin >= b && e >= node[n].end) {
            s_max = max(s_max, node[n].max);
            s_min = min(s_min, node[n].min);
        } else {
            query(n * 2, b, e);
            query(n * 2 + 1, b, e);
        }
    }
}
