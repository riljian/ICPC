#include <cstdio>
using namespace std;
#define MONTH 12

int main() {
    float a, b;
    a = 0.0;
    for (int i = 0; i < MONTH; ++i) {
        scanf("%f", &b);
        a += b;
    }
    printf("$%.2f", a / MONTH);
    return 0;
}
