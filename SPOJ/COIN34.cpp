#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test;
ll xu[35], x;
map<ll, int> mp[2];
map<ll, int>::iterator it, it2;

void duyet(int id, int start, int end, int cnt = 1, ll sum = 0)
{
	for (int i = start + 1; i <= end; ++i)
	{
		it = mp[id].find(sum + xu[i]);

		if (it != mp[id].end())
			(*it).second = max((*it).second, cnt);
		else
			mp[id][sum + xu[i]] = cnt;
		duyet(id, i, end, cnt + 1, sum + xu[i]);
	}
}

void init()
{
	xu[1] = 2, xu[2] = 3, xu[3] = 5;
	for (int i = 4; i <= 34; ++i)
		xu[i] = xu[i-1] + xu[i-2] + xu[i-3];

	duyet(0, 0, 15);
	duyet(1, 15, 34);
}

int main()
{
	init();

	scanf("%d", &test);

	for (int ii = 1; ii <= test; ++ii)
	{
		scanf("%lld", &x);
		int res = -1;
		if ((it = mp[0].find(x)) != mp[0].end())
			res = (*it).second;
		if ((it = mp[1].find(x)) != mp[1].end())
			res = max(res, (*it).second);

		for (it = mp[0].begin(); it != mp[0].end() && (*it).first < x; ++it)
		{
			if ((it2 = mp[1].find(x - (*it).first)) != mp[1].end())
				res = max(res, (*it).second + (*it2).second);
		}

		printf("Case #%d: %d\n", ii, res);
	}
	return 0;
}