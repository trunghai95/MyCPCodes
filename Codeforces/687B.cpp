#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll x, ll y)
{
	if (!x)
		return y;
	return gcd(y%x, x);
}

ll n, k, c, g;

int main()
{
	g = 1;
	scanf("%lld %lld", &n, &k);

	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &c);
		if (c % k == 0)
		{
			printf("Yes");
			return 0;
		}
		if (gcd(c, k) == 1)
			continue;
		ll gg = gcd(g, c);
		g = (g*(c/gg)) % k;
		if (g % k == 0)
		{
			printf("Yes");
			return 0;
		}
	}

	printf("No");
	return 0;
}