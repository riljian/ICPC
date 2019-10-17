#include <cstdio>
#include <cstring>
using namespace std;
#define MAX_NUM 3005

int main() {
  int num;
  bool checked[MAX_NUM], ans;
  int input[MAX_NUM];
  while (~scanf("%d", &num)) {
    memset(checked, false, MAX_NUM * sizeof(bool));
    ans = true;
    for (int i = 0; i < num; ++i) {
      scanf("%d", &input[i]);
    }
    for (int i = 1; i < num; ++i) {
      int a = input[i];
      int b = input[i - 1];
      int diff = a > b ? a - b : b - a;
      if (diff < MAX_NUM) {
        checked[diff] = true;
      }
    }
    for (int i = 1; i < num && ans; ++i) {
      ans = ans && checked[i];
    }
    if (ans) {
      puts("Jolly");
    } else {
      puts("Not jolly");
    }
  }
  return 0;
}
