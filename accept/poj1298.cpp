/* implement */
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXL 1000
#define CHAN 26

int main() {
    char str[MAXL];
    bool first, first_line = true;
    scanf("%s", str);
    do {
        first = true;
        if (!first_line) {
            putchar('\n');
        }
        while (true) {
            scanf("%s", str);
            if (!strcmp(str, "END")) {
                break;
            }
            if (!first) {
                putchar(' ');
            }
            for (int i = 0; i < strlen(str); ++i) {
                if (str[i] >= 'A' && str[i] <= 'Z') {
                    putchar((str[i] + 'V' - 2 * 'A' + CHAN) % CHAN + 'A');
                } else {
                    putchar(str[i]);
                }
            }
            first = false;
        }
        first_line = false;
        scanf("%s", str);
    } while (strcmp(str, "ENDOFINPUT"));
    return 0;
}
