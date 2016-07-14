#include <bits/stdc++.h>

using namespace std;

int test, n, ff;
vector<int> adj[100010];
int dist[100010];

int bfs(int p)
{
	int res = 0;
	queue<int> q;
	memset(dist, -1, n*sizeof(int));
	q.push(p);
	dist[p] = 0;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		res = dist[ff = u];

		for (int i = 0; i < (int)adj[u].size(); ++i)
		if (dist[adj[u][i]] == -1)
			dist[adj[u][i]] = dist[u] + 1, q.push(adj[u][i]);
	}

	return res;
}

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			adj[i].clear();

		for (int i = 1, u, v; i < n; ++i)
		{
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		bfs(0);
		int d = bfs(ff);
		printf("%d\n", (d+1)/2);
	}
	return 0;
}