/* Implement */
#include <cstdio>
using namespace std;
#define MAXN 50001

long long ans[MAXN];

int main() {
  int v;
  ans[1] = 1;
  for (int i = 2; i < MAXN; ++i) {
    long long q = i;
    ans[i] = ans[i - 1] + q * q * q;
  }
  while (~scanf("%d", &v)) {
    printf("%lld\n", ans[v]);
  }
  return 0;
}
