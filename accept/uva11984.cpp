/* implement */
#include <cstdio>
using namespace std;

int main() {
    int n, c = 0;
    float a, b;
    scanf("%d", &n);
    while (n--) {
        scanf("%f%f", &a, &b);
        printf("Case %d: %.2f\n", ++c, a + b * 5 / 9);
    }
    return 0;
}
