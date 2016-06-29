#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int n, q, x, cent[300001], maxx[300001], sum[300001], par[300001][19];
vector<int> child[300001];

void dfs(int &u)
{
	sum[u] = 1;
	for (int i = 1; i < 19; ++i)
	if (par[u][i-1] != -1)
	{
		par[u][i] = par[par[u][i-1]][i-1];
	}
	for (int i = 0; i < (int)child[u].size(); ++i)
	{
		dfs(child[u][i]);
		sum[u] += sum[child[u][i]];
		maxx[u] = max(maxx[u], sum[child[u][i]]);
	}
	if (maxx[u]*2 <= sum[u])
		cent[u] = u;
}

void proc(int &u)
{
	int lo = maxx[u]*2, hi = sum[u]*2;
	int p = u;
	while (1)
	{
		bool f = false;
		for (int i = 18; i >= 0; --i)
		if (par[p][i] != -1 && sum[par[p][i]] < lo)
		{
			p = par[p][i];
			f = true;
			break;
		}

		if (!f)
		{
			if (par[p][0] == -1)
				return;
			p = par[p][0];
			break;
		}
	}

	while (p != -1 && sum[p] <= hi)
		cent[p] = u, p = par[p][0];
}

int main()
{
	scanf("%d %d", &n, &q);

	memset(par, -1, sizeof(par));
	for (int i = 2; i <= n; ++i)
	{
		scanf("%d", &par[i][0]);
		child[par[i][0]].push_back(i);
	}

	x = 1;
	dfs(x);
	for (int i = 1; i <= n; ++i)
		proc(i);

	while (q--)
	{
		scanf("%d", &x);
		printf("%d\n", cent[x]);
	}
	return 0;
}