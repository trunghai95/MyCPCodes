#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
const int LOGMAXN = 10;

int test, n, par[MAXN + 1][LOGMAXN + 1], h[MAXN + 1], q;
vector<int> adj[1010];

void dfs(int v, int p = -1)
{
	par[v][0] = p;
	if (p != -1)
		h[v] = h[p] + 1;
	for (int i = 1; i < LOGMAXN; ++i)
	if (par[v][i-1] != -1)
		par[v][i] = par[par[v][i-1]][i-1];
	for (int i = 0; i < adj[v].size(); ++i)
	if (adj[v][i] != p)
		dfs(adj[v][i], v);
}

int LCA(int v, int u)
{
	if (h[v] < h[u])
		swap(u, v);
	for (int i = LOGMAXN - 1; i >= 0; --i)
	if (par[v][i] != -1 && h[par[v][i]] >= h[u])
		v = par[v][i];
	// now h[v] == h[u]
	if (v == u)
		return v;
	for (int i = LOGMAXN - 1; i >= 0; --i)
	if (par[v][i] != par[u][i])
		v = par[v][i], u = par[u][i];
	return par[v][0];
}

int main()
{
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt)
	{
		memset(par, -1, sizeof(par));
		memset(h, 0, sizeof(h));
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			adj[i].clear();

		for (int i = 1, x, y; i <= n; ++i)
		{
			scanf("%d", &x);
			for (int j = 0; j < x; ++j)
			{
				scanf("%d", &y);
				adj[i].push_back(y);
			}
		}

		dfs(1);
		// for (int i = 1; i <= n; ++i)
		// {
		// 	printf("%d-%d: ", i, h[i]);
		// 	for (int j = 0; j < LOGMAXN && par[i][j] != -1; ++j)
		// 		printf("%d ", par[i][j]);
		// 	printf("\n");
		// }
		scanf("%d", &q);
		printf("Case %d:\n", tt);
		for (int i = 0, u, v; i < q; ++i)
		{
			scanf("%d %d", &u, &v);
			printf("%d\n", LCA(u, v));
		}
	}
	return 0;
}