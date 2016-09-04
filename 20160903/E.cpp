#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

struct Vector {
	int x, y, z;

	bool operator==(Vector v) {
		return x == v.x && y == v.y && z == v.z;
	}
};

int test;
Vector p[2], v[2];
int r[2];

double dist(double t) {
	double a[2][3];
	for (int i = 0; i < 2; ++i) {
		a[i][0] = t * v[i].x + p[i].x;
		a[i][1] = t * v[i].y + p[i].y;
		a[i][2] = t * v[i].z + p[i].z;
	}

	double res = 0;
	for (int i = 0; i < 3; ++i)
		res += (a[0][i] - a[1][i]) * (a[0][i] - a[1][i]);
	return sqrt(res);
}

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		for (int i = 0; i < 2; ++i) {
			scanf("%d %d %d %d %d %d %d", &p[i].x, &p[i].y, &p[i].z,
				&r[i], &v[i].x, &v[i].y, &v[i].z);
		}

		if (p[0] == p[1]) {
			printf("0.000\n");
			continue;
		}

		if (v[0] == v[1]) {
			printf("No collision\n");
			continue;
		}

		double lo = 0, hi = 2e18;

		while (hi - lo > EPS) {
			double mid1 = lo + (hi - lo) / 3;
			double mid2 = hi - (hi - lo) / 3;

			double d1 = dist(mid1);
			double d2 = dist(mid2);

			if (d1 < d2)
				hi = mid2;
			else
				lo = mid1;
		}

		if (dist(lo) > EPS + r[0] + r[1]) {
			printf("No collision\n");
			continue;
		}

		hi = lo, lo = 0;

		while (hi - lo > EPS) {
			double mid = (lo + hi) / 2;
			double d = dist(mid);
			if (d < r[0] + r[1])
				hi = mid;
			else
				lo = mid;
		}

		printf("%.3lf\n", lo);
	}
	return 0;
}