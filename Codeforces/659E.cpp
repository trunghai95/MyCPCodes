#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[100010];
int prev[100010];

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0, u, v; i < m; ++i)
	{
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int res = 0;

	for (int i = 1; i <= n; ++i)
	if (!prev[i])
	{
		int flag = 1;
		queue<int> q;
		prev[i] = -1;
		q.push(i);

		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (int j = 0; j < adj[u].size(); ++j)
			{
				if (!prev[adj[u][j]])
					prev[adj[u][j]] = u, q.push(adj[u][j]);
				else if (adj[u][j] != prev[u])
					flag = 0;
			}
		}

		res += flag;
	}

	printf("%d", res);
	return 0;
}