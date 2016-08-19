#include <bits/stdc++.h>

using namespace std;

struct Point {
	double x, y;
	int id;
};

int n;
double s;
Point p[200010];
char name[200010][50];

int get(Point a, double s) {
	if (a.x > s/2) {
		if (a.y > s/2)
			return 2;
		else
			return 3;
	} else {
		if (a.y > s/2)
			return 1;
		else
			return 0;
	}
}

bool cmp(Point a, Point b, double s) {
	int da = get(a, s);
	int db = get(b, s);
	if (da < db)
		return true;
	else if (da > db)
		return false;
	else {
		if (da == 0) {
			swap(a.x, a.y);
			swap(b.x, b.y);
		} else if (da == 1) {
			a.y -= s/2;
			b.y -= s/2;
		} else if (da == 2) {
			a.x -= s/2;
			a.y -= s/2;
			b.x -= s/2;
			b.y -= s/2;
		} else {
			a.x -= s/2;
			b.x -= s/2;
			swap(a.x, a.y);
			swap(b.x, b.y);
			a.y = s/2 - a.y;
			b.y = s/2 - b.y;
			a.x = s/2 - a.x;
			b.x = s/2 - b.x;
		}

		return cmp(a, b, s/2);
	}
}

bool operator<(const Point& a, const Point& b) {
	return cmp(a, b, s);
}

int main() {
	scanf("%d %lf", &n, &s);

	for (int i = 0; i < n; ++i) {
		scanf("%lf %lf %s", &p[i].x, &p[i].y, name[i]);
		p[i].id = i;
	}

	sort(p, p+n);

	for (int i = 0; i < n; ++i)
		printf("%s\n", name[p[i].id]);
	return 0;
}