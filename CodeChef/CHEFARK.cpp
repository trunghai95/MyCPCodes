#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MODD = 1e9 + 7;

ll myPow(ll a, ll b)
{
	if (!b) return 1;
	ll tmp = myPow(a, b>>1);
	tmp = tmp*tmp % MODD;
	if (b&1)
		tmp = tmp*a % MODD;
	return tmp;
}

int test, x, n, k, cnt0;
ll res;

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %d", &n, &k);
		cnt0 = 0;
		for (int i = 0; i < n; ++i)
			scanf("%d", &x), cnt0 += (x == 0);
		n -= cnt0;
		// n = min(n - cnt0, k);

		if (cnt0)
		{
			ll tu = 1, mau = 1, tt = n, mm = 1;
			res = 1;
			while (tt > max(n-k, 0))
			{
				tu = tu * tt % MODD;
				mau = mau * mm % MODD;
				--tt, ++mm;
				ll tmp = tu * myPow(mau, MODD - 2) % MODD;
				res = (res + tmp) % MODD;
			}
		}
		else
		{
			ll tu = 1, mau = 1, tt, mm;
			if (k&1)
				res = n, tt = n-1, mm = 2, tu = n;
			else
				res = 1, tt = n, mm = 1;
			// cout << res << ' ' << tt << ' ' << mm << '\n';
			while (tt > max(n-k, 0) + 1)
			{
				tu = (tu * tt % MODD) * (tt - 1) % MODD;
				mau = (mau * mm % MODD) * (mm + 1) % MODD;
				// cout << tu << ' ' << mau << '\n';
				tt -= 2, mm += 2;
				ll tmp = tu * myPow(mau, MODD - 2) % MODD;
				res = (res + tmp) % MODD;
			}
		}

		printf("%lld\n", res);
	}
	return 0;
}