/* stack, queue, priority_queue */
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;
#define ST 0x01
#define QU 0x02
#define PQ 0x04

int main() {
    int a, b, n, pos;
    stack<int> s;
    queue<int> q;
    priority_queue<int> pq;
    while (~scanf("%d", &n)) {
        while (!s.empty()) {
            s.pop();
        }
        while (!q.empty()) {
            q.pop();
        }
        while (!pq.empty()) {
            pq.pop();
        }
        pos = ST | QU | PQ;
        while (n--) {
            scanf("%d %d", &a, &b);
            if (a == 1) {
                s.push(b);
                q.push(b);
                pq.push(b);
            } else {
                if (s.empty()) {
                    pos = 0;
                    continue;
                }
                if (s.top() != b) {
                    pos &= ~ST;
                }
                if (q.front() != b) {
                    pos &= ~QU;
                }
                if (pq.top() != b) {
                    pos &= ~PQ;
                }
                s.pop();
                q.pop();
                pq.pop();
            }
        }
        switch (pos) {
            case 0:
                puts("impossible");
                break;
            case ST:
                puts("stack");
                break;
            case QU:
                puts("queue");
                break;
            case PQ:
                puts("priority queue");
                break;
            default:
                puts("not sure");
        }
    }
    return 0;
}
