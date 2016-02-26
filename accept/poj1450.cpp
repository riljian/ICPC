#include <cstdio>
using namespace std;

int main() {
    int a, b, c = 0, cases;
    scanf("%d", &cases);
    while (c < cases) {
        if (c) {
            putchar('\n');
        }
        scanf("%d%d", &a, &b);
        printf("Scenario #%d\n%d.00\n", ++c, a * b);
    }
    return 0;
}
