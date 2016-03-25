#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

#define F first
#define S second

int test, n, i, it[400000];
pii a[40010];
bool ck[40010];

void ITupdate(int node, int lef, int rig, int l, int r, int val)
{
	if (rig < l || r < lef || lef > rig)
		return;

	if (lef == rig)
	{
		it[node] = val;
		return;
	}

	if (it[node])
	{
		it[node*2] = it[node*2+1] = it[node];
		it[node] = 0;
	}

	if (lef >= l && rig <= r)
		it[node] = val;
	else
	{
		int mid = (lef + rig) / 2;
		ITupdate(node*2, lef, mid, l, r, val);
		ITupdate(node*2 + 1, mid + 1, rig, l, r, val);
	}
}

int ITquery(int node, int lef, int rig, int p)
{
	if (lef == rig && lef == p)
		return it[node];

	if (it[node] && lef != rig)
	{
		it[node*2] = it[node*2+1] = it[node];
		it[node] = 0;
	}

	if (p <= rig && p >= lef)
	{
		int mid = (lef + rig) / 2;
		return max(ITquery(node*2, lef, mid, p), ITquery(node*2+1, mid+1, rig, p));
	}

	return -1;
}

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d", &n);
		map<int,int> mp;

		for (i = 1; i <= n; ++i)
			scanf("%d %d", &a[i].F, &a[i].S), mp[a[i].F], mp[a[i].S];

		map<int,int>::iterator ite = mp.begin();
		int cnt = 0;
		while (ite != mp.end())
		{
			(*ite).S = ++cnt;
			++ite;
		}

		memset(it, 0, sizeof(it));

		for (i = 1; i <= n; ++i)
			ITupdate(1, 1, 80000, mp[a[i].F], mp[a[i].S], i);

		memset(ck, 0, sizeof(ck));
		int res = 0;
		for (i = 1; i <= cnt; ++i)
		{
			int pp = ITquery(1, 1, 80000, i);
			if (!ck[pp])
				++res, ck[pp] = true;
		}

		printf("%d\n", res);
	}
	return 0;
}