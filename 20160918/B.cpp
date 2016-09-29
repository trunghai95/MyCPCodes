#include <bits/stdc++.h>

using namespace std;

int n, m, nn;
double p[20], a[20], sum;

int popcount(int x) {
	int res = 0;
	while (x) {
		res += (x&1);
		x >>= 1;
	}
	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	nn = (1 << n);

	for (int i = 0; i < n; ++i)
		scanf("%lf", p+i);

	for (int i = 0; i < nn; ++i) {
		int cnt = popcount(i);
		if (cnt != m)
			continue;

		double tmp = 1;
		for (int j = 0; j < n; ++j) {
			if ((i >> j) & 1) {
				tmp *= p[j];
			} else {
				tmp *= (1.0 - p[j]);
			}
		}

		for (int j = 0; j < n; ++j) {
			if ((i >> j) & 1) {
				a[j] += tmp;
			}
		}

		sum += tmp;
	}

	for (int i = 0; i < n; ++i)
		printf("%.6lf\n", a[i] / sum);
	return 0;
}