/* segment intersect */
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 100000

struct Point {
	int x, y;
};

bool on_segment(Point pi, Point pj, Point pk) {
	if (min(pi.x, pj.x) <= pk.x && pk.x <= max(pi.x, pj.x) &&
				min(pi.y, pj.y) <= pk.y && pk.y <= max(pi.y, pj.y)) {
		return true;
	} else {
		return false;
	}
}

bool intersect(Point p1, Point p2, Point p3, Point p4) {
	int d1, d2, d3, d4;
	d1 = (p1.x - p3.x) * (p4.y - p3.y) - (p4.x - p3.x) * (p1.y - p3.y);
	d2 = (p2.x - p3.x) * (p4.y - p3.y) - (p4.x - p3.x) * (p2.y - p3.y);
	d3 = (p3.x - p1.x) * (p2.y - p1.y) - (p2.x - p1.x) * (p3.y - p1.y);
	d4 = (p4.x - p1.x) * (p2.y - p1.y) - (p2.x - p1.x) * (p4.y - p1.y);
	if (d1 * d2 < 0 && d3 * d4 < 0) {
		return true;
	} else {
		if (!d1 && on_segment(p3, p4, p1)) {
			return true;
		} else if (!d2 && on_segment(p3, p4, p2)) {
			return true;
		} else if (!d3 && on_segment(p1, p2, p3)) {
			return true;
		} else if (!d4 && on_segment(p1, p2, p4)) {
			return true;
		} else {
			return false;
		}
	}
}

int main() {
	int cases, n, ans;
	bool first = true;
	Point points[MAXN][2];
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d", &n);
		ans = n;
		for (int i = 0; i < n; ++i) {
			scanf("%d %d %d %d", &points[i][0].x, &points[i][0].y, &points[i][1].x, &points[i][1].y);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (intersect(points[i][0], points[i][1], points[j][0], points[j][1])) {
					ans += 2;
				}
			}
		}
		if (!first) {
			putchar('\n');
		}
		printf("%d\n", ans);
		first = false;
	}
	return 0;
}
