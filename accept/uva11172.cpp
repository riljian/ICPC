#include <cstdio>
using namespace std;

int main() {
  int cases, a, b;
  scanf("%d", &cases);
  while (cases--) {
    scanf("%d %d", &a, &b);
    if (a == b) {
      puts("=");
    } else if (a > b) {
      puts(">");
    } else {
      puts("<");
    }
  }
  return 0;
}
