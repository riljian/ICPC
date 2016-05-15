/* minimum spanning tree */
#include <cstdio>
using namespace std;

int main() {
    int n, c = 0;
    while (~scanf("%d", &n) && n) {
        // ((n * (n - 1)) / 2) / (n - 1) = (n / 2)
        printf("Case %d: %d\n", ++c, n / 2);
    }
    return 0;
}
