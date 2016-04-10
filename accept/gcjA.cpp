#include <cstdio>
#include <cstring>
using namespace std;
#define MAXL 20
#define FIN 0x3ff

int main() {
    int cases, flag;
    long long n, ans, inc;
    char number[MAXL];
    scanf("%d", &cases);
    for (int c = 1; c <= cases; ++c) {
        scanf("%lld", &n);
        printf("Case #%d: ", c);
        if (n) {
            inc = flag = 0;
            while (flag != FIN) {
                ++inc;
                ans = n * inc;
                sprintf(number, "%lld", ans);
                for (int i = 0; i < strlen(number); ++i) {
                    flag |= 1 << (number[i] - '0');
                }
            }
            printf("%lld\n", ans);
        } else {
            puts("INSOMNIA");
        }
    }
    return 0;
}
