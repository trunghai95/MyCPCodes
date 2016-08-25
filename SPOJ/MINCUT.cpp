// 10/100 .__.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, x, y, u, v, k;
ll a[1010][1010];

ll sum(int x, int y, int u, int v) {
	if (x > u || y > v)
		return 0;
	return a[u][v] - a[u][y-1] - a[x-1][v] + a[x-1][y-1];
}

int main() {
	freopen("MINCUT.OUT", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
		scanf("%lld", a[i]+j), a[i][j] += a[i][j-1];

	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
		a[i][j] += a[i-1][j];

	while (k --> 0) {
		scanf("%d %d %d %d", &x, &y, &u, &v);

		ll res = 1e18;

		int lo = x, hi = u;

		while (lo < hi) {
			int mid = (lo + hi) / 2;

			ll tmp = sum(x, y, mid, v) - sum(mid+1, y, u, v);
			if (tmp < 0)
				lo = mid + 1;
			else
				hi = mid;
		}

		res = min(res, abs(sum(x, y, lo, v) - sum(lo + 1, y, u, v)));
		res = min(res, abs(sum(x, y, lo - 1, v) - sum(lo, y, u, v)));

		lo = y, hi = v;

		while (lo < hi) {
			int mid = (lo + hi) / 2;

			ll tmp = sum(x, y, u, mid) - sum(x, mid+1, u, v);
			if (tmp < 0)
				lo = mid + 1;
			else
				hi = mid;
		}

		res = min(res, abs(sum(x, y, u, lo) - sum(x, lo+1, u, v)));
		res = min(res, abs(sum(x, y, u, lo-1) - sum(x, lo, u, v)));

		printf("%lld\n", res);
	}
	return 0;
}