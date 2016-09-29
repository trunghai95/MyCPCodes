#include <bits/stdc++.h>

using namespace std;

const double PERI = 10000.0;
int n, m;
double a[2010], b[2010];
double res;

int main() {
	freopen("graveyard.in", "r", stdin);
	freopen("graveyard.out", "w", stdout);

	scanf("%d %d", &n, &m);
	m += n;

	for (int i = 0; i < n; ++i) {
		a[i] = (PERI*i/n);
	}

	for (int i = 0; i < m; ++i) {
		b[i] = (PERI*i/m);
	}

	b[m] = 10000;

	int j = 1, i = 1;
	while (i < n) {
		if (j == m-1 || abs(a[i] - b[j]) <= abs(a[i] - b[j+1])) {
			res += abs(a[i] - b[j]);
			++i;
		}

		++j;
	}

	printf("%.4lf\n", res);

	return 0;
}