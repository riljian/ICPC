/* implement */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXL 30

double func(char []);

int main() {
    char name1[MAXL], name2[MAXL];
    double a, b;
    while (fgets(name1, sizeof(name1), stdin)) {
        fgets(name2, sizeof(name2), stdin);
        a = func(name1);
        b = func(name2);
        printf("%.2lf %%\n", min(a, b) / max(a, b) * 100.0);
    }
    return 0;
}

double func(char str[]) {
    int ans = 0, tmp;
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            ans += str[i] - 'a' + 1;
        } else if (str[i] >= 'A' && str[i] <= 'Z') { 
            ans += str[i] - 'A' + 1;
        }
    }
    while (ans >= 10) {
        tmp = ans;
        ans = 0;
        for (int i = 1000; i >= 1; i /= 10) {
            ans += tmp / i;
            tmp %= i;
        }
    }
    return (double) ans;
}
