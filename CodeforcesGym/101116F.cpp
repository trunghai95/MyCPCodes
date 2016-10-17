#include <bits/stdc++.h>

using namespace std;

const double R = 6371;

int test;
double a[2], b[2];

int main() {

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif

	scanf("%d", &test);

	while (test --> 0) {
		for (int i = 0; i < 2; ++i)
			scanf("%lf %lf", a+i, b+i);

		double res1, res2;

		double r = R * cos(a[0]/180*M_PI);

		double dif = abs(b[0] - b[1]);
		if (dif > 180) {
			dif = 360 - dif;
		}

		res2 = dif/360 * M_PI * r * 2;

		dif = abs(a[0] - a[1]);
		res2 += dif/360 * M_PI * R * 2;

		double x[2], y[2], z[2];
		for (int i = 0; i < 2; ++i) {
			double rad = b[i]/180*M_PI;
			x[i] = cos(rad) * R;
			y[i] = sin(rad) * R;

			bool neg = (a[i] < 0);
			rad = abs(a[i]/180*M_PI);
			z[i] = sin(rad) * R;
			x[i] *= cos(rad);
			y[i] *= cos(rad);

			if (neg) z[i] = -z[i];
		}

		double c = sqrt((x[0] - x[1]) * (x[0] - x[1])
			+ (y[0] - y[1]) * (y[0] - y[1])
			+ (z[0] - z[1]) * (z[0] - z[1]));
		double alpha = asin(c/2.0/R) * 2;
		res1 = alpha / (M_PI * 2) * M_PI * R * 2;

		printf("%.8lf %.8lf\n", res1, res2);
	}
	return 0;
}