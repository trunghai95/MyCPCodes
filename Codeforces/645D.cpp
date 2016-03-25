#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

#define F first
#define S second

int n, m, parNum[100010];
vector<pii> child[100010], parent[100010];
bool ck[100010];

bool Try(int mid)
{
	memset(ck, 0, sizeof(ck));
	memset(parNum, 0, sizeof(parNum));
	int q = -1;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < parent[i].size() && parent[i][j].S <= mid; ++j)
			++parNum[i];

		if (!parNum[i])
		{
			if (q == -1)
				q = i;
			else
				return false;
		}
	}

	while (1)
	{
		int u = q;
		q = -1;
		ck[u] = true;

		for (int i = 0; i < child[u].size() && child[u][i].S <= mid; ++i)
		{
			if (!(--parNum[child[u][i].F]))
			{
				if (q == -1)
					q = child[u][i].F;
				else
					return false;
			}
		}
		if (q == -1)
			break;
	}

	for (int i = 1; i <= n; ++i)
	if (!ck[i])
		return false;

	return true;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1, u, v; i <= m; ++i)
	{
		scanf("%d %d", &u, &v);
		parent[v].push_back(pii(u, i));
		child[u].push_back(pii(v, i));
	}

	int lef = 1, rig = m;

	while (lef < rig)
	{
		int mid = (lef + rig) / 2;
		if (Try(mid))
			rig = mid;
		else
			lef = mid + 1;
	}

	if (lef == m && !Try(lef))
		printf("-1");
	else
		printf("%d", lef);
	return 0;
}