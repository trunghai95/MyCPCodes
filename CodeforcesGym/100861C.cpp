//WA

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, N;
ll a[100000];

int main() {
	scanf("%d %d", &n, &m);

	if (n < m) swap(n, m);

	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j) {
		scanf("%lld", &a[(i-1)*m + j]);
	}

	if (n == 1) {
		printf("%lld\n", a[1] * 4);
		return 0;
	}

	if (m == 1) {
		printf("%lld\n", a[1] + a[2] + a[n] * n * 2);
		return 0;
	}

	N = (n+m) * 2 - 4;

	ll res = a[N] * n + a[N-n-m+2] * m + a[N-n-m+3] * n + a[N-n+2] * m;
	res = min(res, a[N] * n + a[N-n-m+2] * n + a[N-n-m+3] * m + a[N-n+2] * m);
	res = min(res, a[N] * m + a[N-n-m+2] * m + a[N-n-m+3] * n + a[N-m+2] * n);
	res = min(res, a[N] * m + a[N-n-m+2] * n + a[N-n-m+3] * m + a[N-m+2] * n);

	printf("%lld\n", res);

	return 0;
}