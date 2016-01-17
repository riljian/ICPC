/* bubble sort */
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 1005

int main() {
    int n, input[MAXN], ans;
    while (~scanf("%d", &n)) {
        ans = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &input[i]);
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                if (input[j] > input[j + 1]) {
                    swap(input[j], input[j + 1]);
                    ++ans;
                }
            }
        }
        printf("Minimum exchange operations : %d\n", ans);
    }
    return 0;
}
