#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, x, y;
map<int,ll> mp1, mp2;
ll res;

int main()
{
	scanf("%d", &n);

	while (n--)
	{
		scanf("%d %d", &x, &y);
		++mp1[x+y];
		++mp2[x-y];
	}

	map<int,ll>::iterator it = mp1.begin();

	while (it != mp1.end())
		res += (*it).second * ((*it).second - 1) / 2, ++it;

	it = mp2.begin();

	while (it != mp2.end())
		res += (*it).second * ((*it).second - 1) / 2, ++it;

	printf("%lld", res);
	return 0;
}