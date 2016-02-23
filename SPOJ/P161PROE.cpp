#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
bool notPrime[100010], ck[100010];
ll res[100010];

void init()
{
	for (int i = 2; i*i <= 100000; ++i)
	if (!notPrime[i])
	{
		for (int j = i*i; j <= 100000; j += i)
			notPrime[j] = true;
	}
}

ll myPow(ll a, ll b)
{
	if (b == 1)
		return a;

	ll tmp = myPow(a, b/2);
	tmp = (tmp*tmp) % n;

	if (b&1)
		tmp = (tmp*a) % n;
	return tmp;
}

int main()
{
	scanf("%lld", &n);

	if (notPrime[n])
	{
		printf("NO");
		return 0;
	}

	if (n < 4)
	{
		printf("YES\n");
		for (ll i = 1; i <= n; ++i)
			printf("%lld\n", i);
		return 0;
	}

	res[1] = 1, res[2] = 2, res[n] = n;
	ck[1] = ck[2] = ck[n] = true;
	ck[0] = true;

	for (ll i = 3; i < n; ++i)
	{
		ll tmp = (i * myPow(i-1, n-2)) % n;
		if (ck[tmp])
		{
			printf("NO");
			return 0;
		}
		res[i] = tmp;
		ck[tmp] = true;
	}

	printf("YES\n");
	for (int i = 1; i <= n; ++i)
		printf("%lld\n", res[i]);
	return 0;
}