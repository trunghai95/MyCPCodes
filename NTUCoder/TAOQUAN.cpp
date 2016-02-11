#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m, k;

bool check(ll x)
{
	return x*2 <= n && x <= m && x*3 <= n + m - k;
}

int main()
{
	cin >> n >> m >> k;

	ll lef = 0, rig = 1e9;

	while (lef < rig - 1)
	{
		ll mid = (lef + rig)/2;
		if (check(mid))
			lef = mid;
		else
			rig = mid - 1;
	}

	if (check(rig))
		cout << rig;
	else
		cout << lef;
	return 0;
}