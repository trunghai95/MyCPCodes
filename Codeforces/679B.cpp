#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll cbrt(ll x)
{
	ll lef = 0, rig = min(x, 1000000LL);
	while (lef < rig)
	{
		ll mid = (lef + rig) / 2 + 1;
		if (mid*mid*mid <= x)
			lef = mid;
		else
			rig = mid - 1;
	}
	return lef;
}

ll resCnt = 0, resX = 0;
vector<ll> v;

void Try(ll m)
{
	if (v.size() >= resCnt)
	{
		ll s = 0;
		for (int i = (int)v.size() - 1; i >= 0; --i)
			s += v[i]*v[i]*v[i];
		if (v.size() > resCnt || (v.size() == resCnt && s > resX))
		{
			resCnt = v.size(), resX = s;
		}
	}

	if (!m)
		return;
	ll a = cbrt(m);
	v.push_back(a);
	Try(m - a*a*a);
	v.pop_back();

	if (a > 1)
	{
		v.push_back(a-1);
		Try(a*a*a - 1 - (a-1)*(a-1)*(a-1));
		v.pop_back();
	}
}

int main()
{
	ll m;
	scanf("%lld", &m);
	Try(m);
	printf("%lld %lld", resCnt, resX);
	return 0;
}