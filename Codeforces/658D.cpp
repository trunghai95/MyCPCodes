//////////  WA
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

int n;
ll k, a[200010], pre1[200010], pre2[200010], suf1[200010], suf2[200010];
ll pow1[200010], pow2[200010];

void init()
{
	pow1[0] = pow2[0] = 1;
	for (int i = 1; i <= 200005; ++i)
	{
		pow1[i] = (pow1[i-1] * 2) % MOD1;
		pow2[i] = (pow2[i-1] * 2) % MOD2;
	}
}

ll logPow(ll x, ll y, ll modd)
{
	if (y == 0)
		return 1;

	ll tmp = logPow(x, y/2, modd);

	tmp = (tmp*tmp) % modd;
	if (y&1)
		tmp = (tmp*x) % modd;
	return tmp;
}

int main()
{
	init();
	scanf("%d %lld", &n, &k);

	for (int i = 0; i <= n; ++i)
		scanf("%lld", a+i);

	for (int i = 0; i <= n; ++i)
	{
		pre1[i] = (a[i] * pow1[i]) % MOD1;
		pre2[i] = (a[i] * pow2[i]) % MOD2;
	}

	for (int i = n; i >= 0; --i)
	{
		suf1[i] = (suf1[i+1] + pre1[i]) % MOD1;
		suf2[i] = (suf2[i+1] + pre2[i]) % MOD2;
	}

	for (int i = 1; i <= n; ++i)
	{
		pre1[i] += pre1[i-1];
		pre2[i] += pre2[i-1];
	}

	int cnt = 0;

	for (int i = 0; i <= n; ++i)
	{
		ll sum1, sum2, res1, res2;
		if (i == 0)
		{
			sum1 = (MOD1*MOD1 - suf1[1]) % MOD1;
			sum2 = (MOD2*MOD2 - suf2[1]) % MOD2;
		}
		else
		{
			sum1 = (MOD1*MOD1 - pre1[i-1] - suf1[i+1]) % MOD1;
			sum2 = (MOD2*MOD2 - pre2[i-1] - suf2[i+1]) % MOD2;
		}

		res1 = (sum1 * logPow(pow1[i], MOD1 - 2, MOD1)) % MOD1;
		res2 = (sum2 * logPow(pow2[i], MOD2 - 2, MOD2)) % MOD2;

		if ((sum1 + res2 * pow1[i]) % MOD1 == 0 && res2 <= k)
			++cnt;
		else if ((sum2 + res1 * pow2[i]) % MOD2 == 0 && res1 <= k)
			++cnt;
	}

	printf("%d", cnt);
	return 0;
}