#include <bits/stdc++.h>

using namespace std;

const double EPS = 0.001;

int n, res;
double d, a[3], t[3], tmp;
double p[2][3], h[3];

int main() {
	scanf("%d %lf", &n, &d);

	for (int i = 0; i < 2; ++i)
	for (int j = 0; j < 3; ++j)
		scanf("%lf", &p[i][j]);

	for (int i = 0; i < 3; ++i)
		h[i] = p[0][(i+1)%3]*p[1][(i+2)%3] - p[1][(i+1)%3]*p[0][(i+2)%3];

	for (int i = 0; i < n; ++i) {
		for (int i = 0; i < 3; ++i)
			scanf("%lf", a+i);
		for (int i = 0; i < 3; ++i)
			scanf("%lf", t+i), a[i] -= t[i] * d;

		tmp = 0.0;
		for (int i = 0; i < 3; ++i)
			tmp += h[i] * a[i];
		
		if (abs(tmp) > EPS)
			continue;

		tmp = sqrt(a[0]*a[0] + a[1]*a[1] + a[2]*a[2]);
		if (abs(tmp - d) < EPS)
			++res;
	}

	printf("%d\n", res);
	return 0;
}