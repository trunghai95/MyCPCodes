// WA
#include <bits/stdc++.h>

using namespace std;

int m, n, k, deg[100010];
vector<int> adj[100010];
bool ck[100010];

int main()
{
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0, u, v; i < m; ++i)
	{
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
		++deg[u], ++deg[v];
	}

	vector<int> v;

	for (int i = 1; i <= n; ++i)
	if (deg[i] < k)
	{
		v.push_back(i);
		ck[i] = true;
	}

	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < adj[i].size(); ++j)
		if (!ck[adj[i][j]])
		{
			if (--deg[adj[i][j]] < k)
			{
				v.push_back(adj[i][j]);
				ck[adj[i][j]] = true;
			}
		}
	}

	printf("%d\n", n - v.size());

	for (int i = 1; i <= n; ++i)
	if (!ck[i])
		printf("%d ", i);
	return 0;
}