#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int n, m, dist[3001][3001], resMax;
vector<int> adj[3001];
int res[4];
vector<pii> ds[3001], dsr[3001];

void bfs(int p)
{
	queue<int> q;
	q.push(p);
	dist[p][p] = 0;

	while (!q.empty())
	{
		int u = q.front(); q.pop();

		for (int i = 0; i < (int)adj[u].size(); ++i)
		if (dist[p][adj[u][i]] == -1)
		{
			q.push(adj[u][i]);
			dist[p][adj[u][i]] = dist[p][u] + 1;
			ds[p].push_back(pii(dist[p][adj[u][i]], adj[u][i]));
			dsr[adj[u][i]].push_back(pii(dist[p][adj[u][i]], p));
		}
	}
}

void Try(int b, int c)
{
	if (dsr[b].empty() || ds[c].empty())
		return;

	int ib = 0, ic = 0;
	while (ib < dsr[b].size() && dsr[b][ib].second == c)
		++ib;
	if (ib < dsr[b].size())
	{
		int a = dsr[b][ib].second;
		while (ic < ds[c].size() && (ds[c][ic].second == a || ds[c][ic].second == b))
			++ic;
		if (ic < ds[c].size())
		{
			int d = ds[c][ic].second;
			int sum = dist[a][b] + dist[b][c] + dist[c][d];
			if (sum > resMax)
			{
				resMax = sum;
				res[0] = a, res[1] = b, res[2] = c, res[3] = d;
			}
		}
	}

	ib = 0, ic = 0;
	while (ic < ds[c].size() && ds[c][ic].second == b)
		++ic;
	if (ic < ds[c].size())
	{
		int d = ds[c][ic].second;
		while (ib < dsr[b].size() && (dsr[b][ib].second == c || dsr[b][ib].second == d))
			++ib;
		if (ib < dsr[b].size())
		{
			int a = dsr[b][ib].second;
			int sum = dist[a][b] + dist[b][c] + dist[c][d];
			if (sum > resMax)
			{
				resMax = sum;
				res[0] = a, res[1] = b, res[2] = c, res[3] = d;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0, u, v; i < m; ++i)
	{
		scanf("%d %d", &u, &v);
		if (u != v)
			dist[u][v] = 1;
	}

	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j)
	if (dist[i][j])
		adj[i].push_back(j);

	memset(dist, -1, sizeof(dist));

	for (int i = 1; i <= n; ++i)
		bfs(i);

	for (int i = 1; i <= n; ++i)
	{
		sort(ds[i].rbegin(), ds[i].rend());
		sort(dsr[i].rbegin(), dsr[i].rend());
	}

	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j)
	if (dist[i][j] > 0)
		Try(i, j);

	for (int i = 0; i < 4; ++i)
		printf("%d ", res[i]);

	return 0;
}