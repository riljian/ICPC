/* disjoin set */
#include <cstdio>
#include <map>
#include <cstring>
#include <string>
using namespace std;
#define MAXN 100005
#define MAXL 25

int ds[MAXN], ds_size[MAXN];

int find_set(int);
void join_set(int, int);

int main() {
    int cases, n, name_cnt;
    char name1[MAXL], name2[MAXL];
    map<string, int> dic;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        memset(ds_size, 0, sizeof(ds_size));
        name_cnt = -1;
        dic.clear();
        while (n--) {
            scanf("%s %s", name1, name2);
            if (dic.find(name1) == dic.end()) {
                dic[name1] = ++name_cnt;
                ds[name_cnt] = name_cnt;
                ds_size[name_cnt] = 1;
            }
            if (dic.find(name2) == dic.end()) {
                dic[name2] = ++name_cnt;
                ds[name_cnt] = name_cnt;
                ds_size[name_cnt] = 1;
            }
            join_set(dic[name1], dic[name2]);
            printf("%d\n", ds_size[find_set(dic[name1])]);
        }
    }
    return 0;
}

int find_set(int n) {
    if (ds[n] == n) {
        return n;
    } else {
        return ds[n] = find_set(ds[n]);
    }
}

void join_set(int m, int n) {
    m = find_set(m);
    n = find_set(n);
    if (m != n) {
        ds_size[m] += ds_size[n];
        ds[n] = m;
    }
}
