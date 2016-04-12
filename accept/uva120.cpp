#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 35

int main() {
    char line[MAXN * 3], *int_token;
    int n, a[MAXN], b[MAXN];
    while (fgets(line, sizeof(line), stdin)) {
        n = 0;
        printf("%s", line);
        int_token = strtok(line, " \n");
        while (int_token) {
            sscanf(int_token, "%d", &a[n]);
            ++n;
            int_token = strtok(NULL, " \n");
        }
        memcpy(b, a, sizeof(a));
        sort(b, b + n);
        for (int i = n - 1, j; i > 0; --i) {
            if (a[i] != b[i]) {
                for (j = i - 1; a[j] != b[i]; --j);
                if (j) {
                    reverse(a, a + j + 1);
                    printf("%d ", n - j);
                }
                reverse(a, a + i + 1);
                printf("%d ", n - i);
            }
        }
        puts("0");
    }
    return 0;
}
