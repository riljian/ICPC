/* Implement */
#include <cstdio>
using namespace std;

int main() {
  long long a, b;
  while (~scanf("%lld %lld", &a, &b)) {
    printf("%lld\n", a < b ? b - a : a - b);
  }
  return 0;
}
