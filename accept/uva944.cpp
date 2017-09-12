/* dynamic programming */
#include <cstdio>
using namespace std;
#define MAXN 100000
#define INF 0x3f3f3f3f

int ans[MAXN];
int happy(int);
int digitSum(int);

int main() {
  int a, b;
  bool first = true;
  ans[1] = 1;
  while (~scanf("%d %d", &a, &b)) {
    first ? first = false : puts("");
    for (; a <= b; ++a) {
      if (~happy(a)) {
        printf("%d %d\n", a, happy(a));
      }
    }
  }
  return 0;
}

int happy(int v) {
  if (ans[v] == INF) { // visited
    return ans[v] = -1;
  } else if (ans[v]) {
    return ans[v];
  }
  ans[v] = INF; // mark visited
  if (~happy(digitSum(v))) {
    return ans[v] = 1 + happy(digitSum(v));
  } else {
    return ans[v] = -1;
  }
}

int digitSum(int v) {
  int ans = 0;
  while (v) {
    int tmp = v % 10;
    ans += tmp * tmp;
    v /= 10;
  }
  return ans;
}
