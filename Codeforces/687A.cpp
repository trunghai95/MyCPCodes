#include <bits/stdc++.h>

using namespace std;

int n, m, lab[100010];
vector<int> adj[100010], res[2];

int main()
{
	memset(lab, -1, sizeof(lab));
	scanf("%d %d", &n, &m);

	for (int i = 0, u, v; i < m; ++i)
	{
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int p = 1; p <= n; ++p)
	if (lab[p] == -1)
	{
		queue<int> q;
		q.push(p);
		lab[p] = 0;
		res[0].push_back(p);

		while (!q.empty())
		{
			int u = q.front();
			q.pop();

			for (int i = 0; i < (int)adj[u].size(); ++i)
			{
				if (lab[adj[u][i]] != -1)
				{
					if (lab[adj[u][i]] == lab[u])
					{
						printf("-1");
						return 0;
					}
				}
				else
				{
					lab[adj[u][i]] = 1 - lab[u];
					res[lab[adj[u][i]]].push_back(adj[u][i]);
					q.push(adj[u][i]);
				}
			}
		}
	}

	for (int i = 0; i < 2; ++i)
	{
		printf("%d\n", res[i].size());
		for (int j = 0; j < (int)res[i].size(); ++j)
			printf("%d ", res[i][j]);
		printf("\n");
	}
	return 0;
}