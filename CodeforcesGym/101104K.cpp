#include <bits/stdc++.h>

using namespace std;

typedef pair<double,double> pdd;
#define F first
#define S second

int test, n;
double xo, yo, x[2], y[2];

double find(double x, double y) {
	double a = x - xo, b = y - yo;
	a = -a;
	swap(a, b);
	double c = -(a*x + b*y);
	return -c/a;
}

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%d %lf %lf", &n, &xo, &yo);

		vector<pdd> segs;

		for (int i = 0; i < n; ++i) {
			for (int i = 0; i < 2; ++i)
				scanf("%lf %lf", x+i, y+i);

			double f1 = find(x[0], y[0]);
			double f2 = find(x[1], y[1]);
			segs.push_back(pdd(min(f1, f2), max(f1, f2)));
		}

		sort(segs.begin(), segs.end());
		double rig = -2e18;
		int cnt = 0;

		for (int i = 0; i < (int)segs.size(); ++i) {
			if (segs[i].F > rig) {
				++cnt;
				rig = segs[i].S;
			} else {
				rig = max(rig, segs[i].S);
			}
		}

		printf("%d\n", cnt + 1);
	}
	return 0;
}