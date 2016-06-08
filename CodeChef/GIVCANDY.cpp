#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test;
ll a, b, c, d;

ll gcd(ll x, ll y)
{
	if (!x || !y) return x|y;
	return gcd(y, x%y);
}

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

		if (a == b)
		{
			printf("0\n");
			continue;
		}
		ll g = gcd(c, d);
		ll dif = abs(a-b);
		ll tmp = dif / g;
		// cout << g << ' ' << dif << ' ' << tmp << '\n';
		tmp = min(abs(dif - tmp*g), abs(dif - (tmp+1)*g));
		printf("%lld\n", tmp);
	}
	return 0;
}