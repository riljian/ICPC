/* Implement */
#include <cstdio>
using namespace std;

int main() {
  long long a, b, sum;
  int c, cases;
  scanf("%d", &cases);
  while (cases--) {
    sum = 0;
    scanf("%d", &c);
    while (c--) {
      scanf("%lld %*lld %lld", &a, &b);
      sum += a * b;
    }
    printf("%d\n", sum);
  }
  return 0;
}
