#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll k, c[500010], sum;

ll sum1(ll m)
{
	ll res = 0;
	for (int i = 0; i < n; ++i)
	if (c[i] > m)
		res += c[i] - m;
	return res;
}

ll sum2(ll m)
{
	ll res = 0;
	for (int i = 0; i < n; ++i)
	if (c[i] < m)
		res += m - c[i];
	return res;
}

int main()
{
	scanf("%d %lld", &n, &k);

	for (int i = 0; i < n; ++i)
		scanf("%lld", c+i), sum += c[i];

	ll lef = 1, rig = 1e9;
	ll minmax, maxmin;
	while (lef < rig)
	{
		ll mid = (lef + rig) / 2;
		if (sum1(mid) > k)
			lef = mid + 1;
		else
			rig = mid;
	}

	minmax = lef;
	lef = 1, rig = 1e9;
	while (lef < rig)
	{
		ll mid = (lef + rig) / 2;
		if (sum2(mid + 1) > k)
			rig = mid;
		else
			lef = mid + 1;
	}
	maxmin = lef;

	// cout << minmax << ' ' << maxmin << '\n';

	if (minmax <= maxmin)
		printf("%lld", (sum % n != 0)?1LL:0LL);
	else
		printf("%lld", minmax - maxmin);
	return 0;
}