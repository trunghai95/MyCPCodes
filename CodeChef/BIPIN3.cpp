#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;

int test;
ll n, k;

ll modPow(ll x, ll y)
{
	if (y == 0)
		return 1;

	ll tmp = modPow(x, y/2);
	tmp = (tmp*tmp) % MODD;
	if (y&1)
		tmp = (tmp * x) % MODD;
	return tmp;
}

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%lld %lld", &n, &k);
		ll res = (k * modPow(k-1, n-1)) % MODD;
		printf("%lld\n", res);
	}
	return 0;
}