#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test, n;
ll x, m, a[100010];

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %lld %lld", &n, &m, &x);
		for (int i = 0; i < n; ++i)
		{
			scanf("%lld", a+i);
			a[i] = a[i] % m;
		}
		if (x == m - 1)
		{
			printf("%lld\n", n*n);
			continue;
		}

		sort(a, a+n);
		ll res = 0;
		// for (int i = 0; i < n; ++i)
		// 	printf("%lld ", a[i]);
		// printf("\n");

		for (int i = 0; i < n; ++i)
		{
			ll l, r;
			r = x - a[i], l = -a[i];

			while (1)
			{
				int lp = lower_bound(a, a+n, l) - a;
				int rp = lower_bound(a, a+n, r+1) - a;
				// printf("%lld: %lld %d - %lld %d\n", a[i], l, lp, r, rp);
				if (lp == n)
					break;
				res += rp - lp;
				l += m;
				r += m;
			}
		}

		printf("%lld\n", res);
	}
	return 0;
}