/* implement */
#include <cstdio>
#include <algorithm>
using namespace std;

int func(int n) {
	if (n == 1) {
		return 1;
	}
	if (n % 2) {
		return 1 + func(3 * n + 1);
	} else {
		return 1 + func(n / 2);
	}
}

int main() {
	int a, b, ans;
	while (~scanf("%d %d", &a, &b)) {
		printf("%d %d ", a, b);
		if (a > b) {
			swap(a, b);
		}
		ans = -1;
		for (int i = a; i <= b; ++i) {
			ans = max(ans, func(i));
		}
		printf("%d\n", ans);
	}
	return 0;
}
