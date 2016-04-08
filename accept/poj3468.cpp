/* segment tree */
#include <cstdio>
using namespace std;
#define MAXN 100005

struct Node {
    int left, right;
    long long inc, sum;
} tree[MAXN * 4];

void build(int, int, int);
void update(int, int, int, int);
void pushdown(int);
long long query(int, int, int);

int main() {
    int n, m, a, b, c;
    char q;
    scanf("%d %d", &n, &m);
    build(1, 1, n);
    while (m--) {
        getchar(), q = getchar();
        if (q == 'Q') {
            scanf("%d %d", &a, &b);
            printf("%lld\n", query(1, a, b));
        } else {
            scanf("%d %d %d", &a, &b, &c);
            update(1, a, b, c);
        }
    }
    return 0;
}

void build(int n, int l, int r) {
    int mid = (l + r) >> 1;
    tree[n].left = l, tree[n].right = r;
    tree[n].inc = 0;
    if (l < r) {
        build(n * 2, l, mid);
        build(n * 2 + 1, mid + 1, r);
        tree[n].sum = tree[n * 2].sum + tree[n * 2 + 1].sum;
    } else {
        scanf("%lld", &tree[n].sum);
    }
}

void update(int n, int l, int r, int c) {
    if (!(tree[n].left > r || tree[n].right < l)) {
        if (tree[n].left >= l && tree[n].right <= r) {
            tree[n].sum += (tree[n].right - tree[n].left + 1) * c;
            tree[n].inc += c;
        } else {
            pushdown(n);
            update(n * 2, l, r, c);
            update(n * 2 + 1, l, r, c);
            tree[n].sum = tree[n * 2].sum + tree[n * 2 + 1].sum;
        }
    }
}

void pushdown(int n) {
    tree[n * 2].inc += tree[n].inc;
    tree[n * 2 + 1].inc += tree[n].inc;
    tree[n * 2].sum += (tree[n * 2].right - tree[n * 2].left + 1) * tree[n].inc;
    tree[n * 2 + 1].sum += (tree[n * 2 + 1].right - tree[n * 2 + 1].left + 1) * tree[n].inc;
    tree[n].inc = 0;
}

long long query(int n, int l, int r) {
    if (!(tree[n].left > r || tree[n].right < l)) {
        if (tree[n].left >= l && tree[n].right <= r) {
            return tree[n].sum;
        } else {
            pushdown(n);
            return query(n * 2, l, r) + query(n * 2 + 1, l, r);
        }
    }
    return 0;
}
