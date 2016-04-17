#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int n;
pii p[2010];
map<pii, ll> cnt;

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d %d", &p[i].first, &p[i].second);

	for (int i = 0; i < n; ++i)
	for (int j = i + 1; j < n; ++j)
	{
		int f = p[i].first - p[j].first, s = p[i].second - p[j].second;
		if (f < 0)
			f = -f, s = -s;
		else if (f == 0 && s < 0)
			s = -s;
		++cnt[pii(f, s)];
	}

	ll res = 0LL;

	for (map<pii, ll>::iterator it = cnt.begin(); it != cnt.end(); ++it)
	{
		res += (*it).second * ((*it).second - 1) / 2;
	}

	printf("%lld", res/2);
	return 0;
}