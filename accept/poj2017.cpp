/* implement */
#include <cstdio>
using namespace std;

int main() {
    int n, sum, prev, speed, now;
    while (scanf("%d", &n) && ~n) {
        sum = prev = 0;
        while (n--) {
            scanf("%d%d", &speed, &now);
            sum += (now - prev) * speed;
            prev = now;
        }
        printf("%d miles\n", sum);
    }
    return 0;
}
