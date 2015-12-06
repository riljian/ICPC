/* convex hull, graham's scan */
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 100005

struct Point {
	int x, y;
} base;

int cross(Point p0, Point p1, Point p2) {
	return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
}

int dis_square(Point a, Point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool cmp(Point a, Point b) {
	int tmp = cross(base, a, b);
	if (tmp == 0) {
		return dis_square(a, base) > dis_square(b, base);
	} else {
		return tmp > 0;
	}
}

void sort_counterclockwise(Point in[], int n) {
	int minid = 0,
		minx = in[0].x,
		miny = in[0].y;
	for (int i = 1; i < n; ++i) {
		if (in[i].y < miny || (in[i].y == miny && in[i].x < minx)) {
			minx = in[i].x, miny = in[i].y, minid = i;
		}
	}
	swap(in[0], in[minid]);
	base = in[0];
	sort(in + 1, in + n, cmp);
}

int graham_scan(Point in[], int n, Point stack[]) {
	int top = 2;
	sort_counterclockwise(in, n);
	for (int i = 0; i < 3; ++i) {
		stack[i] = in[i];
	}
	for (int i = 3; i < n; ++i) {
		while (cross(stack[top - 1], in[i], stack[top]) >= 0) {
			--top;
			if (top == 1) {
				break;
			}
		}
		stack[++top] = in[i];
	}
	++top;
	return top;
}

bool in_convex(Point convex[], int n, Point p) {
	for (int i = 1; i < n; ++i) {
		if (cross(convex[i - 1], convex[i], p) < 0) {
			return false;
		}
	}
	return cross(convex[n - 1], convex[0], p) >= 0;
}

int main() {
	int n, m, cnt_convex;
	Point A[MAXN], convex[MAXN], B;
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &A[i].x, &A[i].y);
		}
		cnt_convex = graham_scan(A, n, convex);
		scanf("%d", &m);
		while (m--) {
			scanf("%d %d", &B.x, &B.y);
			puts(in_convex(convex, cnt_convex, B) ? "inside" : "outside");
		}
	}
	return 0;
}
