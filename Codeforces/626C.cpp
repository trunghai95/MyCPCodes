#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;

bool check(ll x)
{
	ll a2 = x / 2, a3 = x / 3, a23 = a2 + a3 - x / 6;
	return a2 >= n && a3 >= m && a23 >= (n + m);
}

int main()
{
	cin >> n >> m;

	ll lef = 0, rig = 1e18;

	while (lef < rig)
	{
		ll mid = (rig + lef) / 2;

		if (check(mid))
			rig = mid;
		else
			lef = mid + 1;
	}

	cout << lef;

	return 0;
}