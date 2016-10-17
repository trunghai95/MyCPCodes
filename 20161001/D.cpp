#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, x[50], y[50];
ll cnt[2][900][900];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d %d", x+i, y+i);
	}

	int m = min(n, 20);
	int nn = (1 << m);

	for (int i = 1; i < nn; ++i) {
		int xx = 0, yy = 0;
		for (int j = 0; j < m; ++j)
		if ((i >> j) & 1) {
			xx += x[j];
			yy += y[j];
		}
		++cnt[0][xx + 400][yy + 400];
	}

	m = n - m;
	nn = (1 << m);

	for (int i = 1; i < nn; ++i) {
		int xx = 0, yy = 0;
		for (int j = 0; j < m; ++j)
		if ((i >> j) & 1) {
			xx += x[20 + j];
			yy += y[20 + j];
		}
		++cnt[1][xx + 400][yy + 400];
	}

	ll res = cnt[0][400][400] + cnt[1][400][400];
	for (int i = -400; i <= 400; ++i)
	for (int j = -400; j <= 400; ++j) {
		res += cnt[0][i + 400][j + 400] * cnt[1][-i + 400][-j + 400];
	}

	printf("%lld\n", res);
	return 0;
}