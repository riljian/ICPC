/* implement */
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int h, w, n;
    double p;
    while (~scanf("%d%d", &h, &w) && h) {
        if (h == 1) {
            puts("0 1");
        } else if (w == 1) {
            p = log2(h);
            printf("%.0lf %.0lf\n", p, pow(2, p + 1) - 1);
        } else {
            p = log(h) / log(w);
            for (n = 2; abs(log(n + 1) / log(n) - p) > 0.0000001; ++n);
            printf("%d %d\n", (w - 1) / (n - 1), (n + 1) * h - w * n);
        }
    }
    return 0;
}
