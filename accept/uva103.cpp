/* longest increasing subsequence, LIS */
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 10
#define MAXK 30

int box[MAXK][MAXN], n;
bool cmp(int, int);
bool fit(int, int);

int main() {
    int k, pre[MAXK], ord[MAXK], len[MAXK], max_flag;
    while (~scanf("%d%d", &k, &n)) {
        max_flag = 0;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &box[i][j]);
            }
            sort(box[i], box[i] + n);
            ord[i] = i;
            len[i] = 1;
            pre[i] = -1;
        }
        sort(ord, ord + k, cmp);
        for (int i = 0; i < k; ++i) {
            for (int j = i + 1; j < k; ++j) {
                int l = ord[i], r = ord[j];
                if (fit(l, r) && len[l] >= len[r]) {
                    len[r] = len[l] + 1;
                    pre[r] = l;
                    if (len[r] > len[max_flag]) {
                        max_flag = r;
                    }
                }
            }
        }
        printf("%d\n", len[max_flag]);
        for (int i = max_flag; ~i; i = pre[i]) {
            printf("%d ", i + 1);
        }
        puts("");
    }
    return 0;
}

bool cmp(int l, int r) {
    for (int i = 0; i < n; ++i) {
        if (box[l][i] != box[r][i]) {
            return box[l][i] > box[r][i];
        }
    }
    return true;
}

bool fit(int l, int r) {
    for (int i = 0; i < n; ++i) {
        if (box[l][i] <= box[r][i]) {
            return false;
        }
    }
    return true;
}
