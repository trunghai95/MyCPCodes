#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, k, c[111];
ll p[111][111], f[111][111][111];

ll myMin(ll x, ll y) {
	if (x < 0)
		return y;
	if (y < 0)
		return x;
	return min(x, y);
}

int main() {

	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= n; ++i)
		scanf("%d", c+i);

	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
		scanf("%lld", p[i] + j);

	memset(f, -1, sizeof(f));

	if (c[1])
		f[1][1][c[1]] = 0;
	else for (int i = 1; i <= m; ++i)
		f[1][1][i] = p[1][i];

	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			if (c[i]) {
				f[i][j][c[i]] = f[i-1][j][c[i]];
				for (int t = 1; t <= m; ++t) {
					f[i][j][c[i]] = myMin(f[i][j][c[i]], f[i-1][j-1][t]);
				}
			} else {
				for (int t = 1; t <= m; ++t)
				for (int x = 1; x <= m; ++x) {
					if (t == x && f[i-1][j][x] != -1)
						f[i][j][t] = myMin(f[i][j][t], f[i-1][j][x] + p[i][t]);
					else if (t != x && f[i-1][j-1][x] != -1)
						f[i][j][t] = myMin(f[i][j][t], f[i-1][j-1][x] + p[i][t]);
				}
			}
		}
	}

	ll res = -1;

	for (int i = 1; i <= m; ++i)
		res = myMin(res, f[n][k][i]);

	printf("%lld\n", res);
	return 0;
}