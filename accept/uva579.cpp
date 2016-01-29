#include <cstdio>
using namespace std;
#define abs(x) ((x)<0?(-(x)):(x))
#define half(x) ((x)>180?(360-(x)):(x))

int main() {
    int a, b;
    float h, m;
    while (~scanf("%d:%d", &a, &b) && (a + b)) {
        h = (float) ((a % 12) * 60 + b) / 2;
        m = (float) b * 6;
        printf("%.3f\n", half(abs(h - m)));
    }
    return 0;
}
