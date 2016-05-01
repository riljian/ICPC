#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <utility>
using namespace std;
#define MAXN 1000
#define MAXM 1000
#define MAXT 1000
#define MINT -1000
#define CASE 10

int main() {
    srand(time(NULL));
    int c = CASE, m;
    set<pair<int, int> > s;
    pair<int, int> p;
    printf("%d\n", c);
    while (c--) {
        m = MAXM;
        s.clear();
        printf("\n%d %d\n", MAXN, MAXM);
        while (m) {
            p = make_pair(rand() % MAXN, rand() % MAXN);
            if (p.first != p.second && s.find(p) == s.end()) {
                m--;
                printf("%d %d %d\n", p.first, p.second, rand() % 2000 - 1000);
            }
        }
    }
    return 0;
}
