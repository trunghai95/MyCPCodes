#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll m;

ll cnt(ll x)
{
	ll kkk, res = 0;
	for (ll k = 2; (kkk = k*k*k) <= x; ++k)
		res += x/kkk;
	return res;
}

int main()
{
	cin >> m;

	ll lef = 8, rig = 1e18;

	while (lef < rig)
	{
		ll mid = (lef + rig) / 2;
		ll tmp = cnt(mid);
		if (tmp < m)
			lef = mid + 1;
		else
			rig = mid;
	}

	if (cnt(lef) == m)
		cout << lef;
	else
		cout << -1;
	return 0;
}