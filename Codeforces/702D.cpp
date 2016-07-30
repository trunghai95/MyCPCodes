#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll d, k, a, b, t;

ll f(ll cd)
{
	ll wd = d - cd;
	ll res = wd * b;
	res += cd * a + (cd - 1) / k * t;
	return res;
}

int main()
{
	cin >> d >> k >> a >> b >> t;

	if (b >= a + t || k >= d)
	{
		cout << f(d) << '\n';
		return 0;
	}

	ll res = f(k);

	for (ll i = 0; i <= k; ++i)
		res = min(res, f(d - i));

	cout << res << '\n';
	return 0;
}