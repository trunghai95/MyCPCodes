//WA

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pll;
 
const ll INF = 5e9;
 
int test, n;
ll g1, g2;
ll h[20], m[20];
 
ll getState(ll time)
{
	ll res = 0;
	for (int i = 2; i <= n; ++i)
	{
		ll x = h[i-1] + m[i-1] * time;
		ll y = h[i] + m[i] * time;
 
		res *= 3LL;
		if (x > y)
			res += 1;
		else if (x < y)
			res += 2;
	}
 
	return res;
}
 
void getGoal()
{
	g1 = g2 = 0;
	for (int i = 2; i <= n; ++i)
	{
		g1 = g1 * 3 + 2 - (i&1);
		g2 = g2 * 3 + 2 - !(i&1);
	}
}
 
ll proc(ll state, ll b)
{
	ll lef = 0, rig = b;
 
	while (lef < rig)
	{
		ll mid = (lef + rig) / 2;
		ll s = getState(mid);
		if (s != state)
			lef = mid + 1;
		else
			rig = mid;
	}
 
	return lef;
}
 
int main()
{
	scanf("%d", &test);
 
	while (test--)
	{
		scanf("%d", &n);
 
		for (int i = 1; i <= n; ++i)
			scanf("%lld %lld", h+i, m+i);
 
		if (n == 1)
		{
			printf("1\n0 Inf\n");
			continue;
		}
 
		vector<pll> res;
		getGoal();
 
		ll a, b;
		b = INF;
 
		while (1)
		{
			if (b < 0)
				break;
 
			ll state = getState(b);
			a = proc(state, b);

			if (state == g1 || state == g2)
			{
				if (!res.empty() && res.back().first - 1 == b)
					res.back().first = a;
				else
					res.push_back(pll(a, b));
			}
 
			b = a - 1;
		}
 
		printf("%d\n", (int)res.size());
		for (int i = (int)res.size() - 1; i >= 0; --i)
		{
			printf("%lld ", res[i].first);
			if (res[i].second == INF)
				printf("Inf\n");
			else
				printf("%lld\n", res[i].second);
		}
	}
	return 0;
}