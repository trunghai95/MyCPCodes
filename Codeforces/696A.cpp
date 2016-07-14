#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int q, type;
ll u, v, w;
map<ll,ll> mp;

void update(ll u, ll v, ll w)
{
	while (u != v)
	{
		if (u < v)
		{
			mp[v] += w;
			v /= 2;
		}
		else
		{
			mp[u] += w;
			u /= 2;
		}
	}
}

ll solve(ll u, ll v)
{
	ll res = 0;

	while (u != v)
	{
		if (u < v)
			res += mp[v], v /= 2;
		else
			res += mp[u], u /= 2;
	}

	return res;
}

int main()
{
	scanf("%d", &q);

	while (q--)
	{
		scanf("%d", &type);

		if (type == 1)
		{
			scanf("%lld %lld %lld", &u, &v, &w);
			update(u, v, w);
		}
		else
		{
			scanf("%lld %lld", &u, &v);
			printf("%lld\n", solve(u, v));
		}
	}
	return 0;
}