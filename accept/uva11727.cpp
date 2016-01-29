#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 3

int main() {
    int c = 0, cases, s[MAXN];
    scanf("%d", &cases);
    while (cases--) {
        for (int i = 0; i < MAXN; ++i) {
            scanf("%d", &s[i]);
        }
        sort(s, s + MAXN);
        printf("Case %d: %d\n", ++c, s[1]);
    }
    return 0;
}
