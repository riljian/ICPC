/* merge sort */
#include <cstdio>
using namespace std;
#define MAXN 500005

int buff[MAXN];
void merge(int [], int, int);
void mergeSort(int [], int, int);
long long ans;

int main() {
    int n, input[MAXN];
    while (scanf("%d", &n) && n) {
        ans = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &input[i]);
        }
        mergeSort(input, 0, n - 1);
        printf("%lld\n", ans);
    }
}

void mergeSort(int input[], int low, int high) {
    int mid = (low + high) >> 1;
    if (high > low) {
         mergeSort(input, low, mid);
         mergeSort(input, mid + 1, high);
         merge(input, low, high);
    }
}

void merge(int input[], int low, int high) {
    int t = 0, mid = (low + high) >> 1;
    for (int i = low, j = mid + 1, k = -1; i <= mid || j <= high;) {
        if (i > mid) {
            buff[++k] = input[j++];
        } else if (j > high) {
            buff[++k] = input[i++];
            ans += t;
        } else if (input[i] >= input[j]) {
            buff[++k] = input[j++];
            ++t;
        } else {
            buff[++k] = input[i++];
            ans += t;
        }
    }
    for (int i = low, k = 0; i <= high; ++i) {
        input[i] = buff[k++];
    }
}
