#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second

const int SQRTN = 447;

int n, t, id[200010], lef, rig;
ll a[200010], cnt[1000010], res[200010], cur;
pii query[200010];

bool cmp(const int &x, const int &y)
{
	if (query[x].F / SQRTN == query[y].F / SQRTN)
		return query[x].S < query[y].S;
	return query[x].F < query[y].F;
}

void update(int &l, int &r)
{
	while (lef < l)
	{
		cur += (1LL - cnt[a[lef]] * 2) * a[lef];
		--cnt[a[lef]];
		++lef;
	}

	while (lef > l)
	{
		--lef;
		cur += (1LL + cnt[a[lef]] * 2) * a[lef];
		++cnt[a[lef]];
	}

	while (rig < r)
	{
		++rig;
		cur += (1LL + cnt[a[rig]] * 2) * a[rig];
		++cnt[a[rig]];
	}

	while (rig > r)
	{
		cur += (1LL - cnt[a[rig]] * 2) * a[rig];
		--cnt[a[rig]];
		--rig;
	}
}

int main()
{
	scanf("%d %d", &n, &t);

	for (int i = 1; i <= n; ++i)
		scanf("%lld", a+i);

	for (int i = 1; i <= t; ++i)
		scanf("%d %d", &query[i].F, &query[i].S), id[i] = i;

	sort(id+1, id+1+t, cmp);

	for (int i = 1; i <= t; ++i)
	{
		update(query[id[i]].F, query[id[i]].S);
		res[id[i]] = cur;
	}

	for (int i = 1; i <= t; ++i)
		printf("%lld\n", res[i]);
	return 0;
}