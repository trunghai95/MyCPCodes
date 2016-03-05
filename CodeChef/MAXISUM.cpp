#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, test;
ll a[100010], k, b;

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %lld", &n, &k);

		for (int i = 0; i < n; ++i)
			scanf("%lld", a+i);

		ll mx = -1e18, res = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%lld", &b);
			res += a[i] * b;
			mx = max(mx, abs(b));
		}

		res += k * mx;

		printf("%lld\n", res);
	}
	return 0;
}