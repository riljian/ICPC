/* implement */
#include <cstdio>
using namespace std;

int main() {
    int a, b, c = 0, cases;
    float ans;
    scanf("%d", &cases);
    while (c < cases) {
        if (c) {
            putchar('\n');
        }
        scanf("%d%d", &a, &b);
        ans = (float) a * b;
        if (a & b & 1) {
            ans += 0.41;
        }
        printf("Scenario #%d:\n%.2f\n", ++c, ans);
    }
    return 0;
}
