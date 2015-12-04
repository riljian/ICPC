/* line intersect */
#include <cstdio>
using namespace std;

struct Point {
	int x, y;
};

struct Segment {
	Point s, e;
};

int main() {
	Segment s1, s2;
	int cases, a1, b1, c1, a2, b2, c2, d, dx, dy;
	scanf("%d", &cases);
	puts("INTERSECTING LINES OUTPUT");
	while (cases--) {
		scanf("%d %d %d %d %d %d %d %d", &s1.s.x, &s1.s.y, &s1.e.x, &s1.e.y, &s2.s.x, &s2.s.y, &s2.e.x, &s2.e.y);
		a1 = s1.s.y - s1.e.y;
		b1 = s1.e.x - s1.s.x;
		c1 = a1 * s1.s.x + b1 * s1.s.y;
		a2 = s2.s.y - s2.e.y;
		b2 = s2.e.x - s2.s.x;
		c2 = a2 * s2.s.x + b2 * s2.s.y;
		d = a1 * b2 - b1 * a2;
		dx = c1 * b2 - b1 * c2;
		dy = a1 * c2 - c1 * a2;
		if (d == 0) {
			if (dx || dy) {
				puts("NONE");
			} else {
				puts("LINE");
			}
		} else {
			printf("POINT %.2f %.2f\n", (float) dx / d, (float) dy / d);
		}
	}
	puts("END OF OUTPUT");
	return 0;
}
