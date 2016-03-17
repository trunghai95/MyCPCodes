#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

map<int, ll> cntr, cntc;
map<pii, ll> mp;
int n, x, y;

int main()
{
	scanf("%d", &n);

	while (n--)
	{
		scanf("%d %d", &x, &y);
		++mp[pii(x,y)];
		++cntr[x];
		++cntc[y];
	}

	map<int,ll>::iterator it = cntr.begin();
	ll res = 0;

	while (it != cntr.end())
	{
		res += (*it).second * ((*it).second - 1) / 2;
		++it;
	}

	it = cntc.begin();
	while (it != cntc.end())
	{
		res += (*it).second * ((*it).second - 1) / 2;
		++it;
	}

	map<pii, ll>::iterator it2 = mp.begin();
	while (it2 != mp.end())
	{
		res -= (*it2).second * ((*it2).second - 1) / 2;
		++it2;
	}

	printf("%lld", res);
	return 0;
}