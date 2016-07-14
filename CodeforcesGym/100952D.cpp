#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MODD = 1e9 + 7;

int test, n, m, k, d, x, c;
ll fac[501], invfac[501];

ll myPow(ll x, ll y)
{
	if (y == 0)
		return 1;

	ll res = myPow(x, y/2);
	res = res*res%MODD;
	if (y&1)
		res = res*x%MODD;
	return res;
}

void init()
{
	fac[0] = invfac[0] = 1;
	for (int i = 1; i <= 500; ++i)
	{
		fac[i] = fac[i-1] * i % MODD;
		invfac[i] = myPow(fac[i], MODD - 2);
	}
}

ll C(ll n, ll k)
{
	return (fac[n] * invfac[n-k] % MODD) * invfac[k] % MODD;
}

int main()
{
	init();
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %d %d %d", &n, &m, &k, &d);
		c = 0;

		if (n < m || k > m)
		{
			printf("0\n");
			continue;
		}

		for (int i = 0; i < n; ++i)
			scanf("%d", &x), c += (x >= d);

		ll res = 0;
		for (int i = k; i <= min(c, m); ++i)
		{
			if (m - i > n - c)
				continue;
			res = (res + C(c, i) * C(n - c, m - i) % MODD) % MODD;
		}

		printf("%lld\n", res);
	}
	return 0;
}