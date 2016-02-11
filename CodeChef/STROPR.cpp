#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;

int test, n, x;
ll m, a[100010];

ll myPow(ll x, ll b)
{
	if (b == 1)
		return x;

	ll tmp = myPow(x, b>>1);
	tmp = (tmp*tmp) % MODD;

	if (b&1)
		tmp = (tmp*x) % MODD;

	return tmp;
}

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %d %lld", &n, &x, &m);

		for (int i = 1; i <= n; ++i)
			scanf("%lld", a+i), a[i] %= MODD;

		m %= MODD;

		ll tu = 1, mau = 1, tt = m, mm = 1;
		ll res = a[x];

		for (int i = x-1; i > 0; --i)
		{
			tu = (tu*tt) % MODD, mau = (mau*mm) % MODD;

			ll tmp = (tu * myPow(mau, MODD - 2)) % MODD;
			res = (res + tmp * a[i]) % MODD;

			++tt, ++mm;
		}

		printf("%lld\n", res);
	}
	return 0;
}