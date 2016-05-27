/* implement */
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 105

int main() {
    bool prison[MAXN];
    int c, n, ans;
    scanf("%d", &c);
    while (c--) {
        scanf("%d", &n);
        memset(prison, true, sizeof(prison));
        for (int i = 2; i <= n; ++i) {
            for (int j = i; j <= n; j += i) {
                prison[j] = !prison[j];
            }
        }
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (prison[i]) {
                ++ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
