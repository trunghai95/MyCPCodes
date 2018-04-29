#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

int test, res;
char s[2][50];
map<string, int> id[2];

int getID(int x)
{
	string str(s[x]);
	if (id[x][str] == 0)
		return (id[x][str] = id[x].size());
	return id[x][str];
}

const int MAXN = 1000;
const int MAXM = 1000;
int n1, n2, m, pairU[MAXN+5], pairV[MAXN+5], dist[MAXN+5];
vector<int> adj[MAXN+5];
pii edge[MAXM];

bool bfs()
{
	memset(dist, -1, sizeof(dist));
	queue<int> q;

	for (int u = 1; u <= n1; ++u)
	if (pairU[u] == -1) q.push(u), dist[u] = 0;

	int mx = -1;

	while (!q.empty())
	{
		int u = q.front(); q.pop();

		if (mx != -1 && dist[u] >= mx) continue;

		for (int i = 0; i < (int)adj[u].size(); ++i)
		{
			int v = adj[u][i];
			if (pairV[v] == -1) mx = dist[u];
			else if (dist[pairV[v]] == -1)
				dist[pairV[v]] = dist[u] + 1, q.push(pairV[v]);
		}
	}

	return (mx != -1);
}

bool dfs(int u)
{
	for (int i = 0; i < (int)adj[u].size(); ++i)
	{
		int v = adj[u][i];

		if (pairV[v] == -1 || (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v])))
		{
			pairV[v] = u;
			pairU[u] = v;
			return true;
		}
	}

	dist[u] = -1;
	return false;
}

int maxMatching()
{
	memset(pairU, -1, sizeof(pairU));
	memset(pairV, -1, sizeof(pairV));
	int res = 0;

	while (bfs())
	{
		for (int u = 1; u <= n1; ++u)
			if (pairU[u] == -1 && dfs(u)) ++res;
	}
	return res;
}

int main()
{
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt)
	{
		id[0].clear();
		id[1].clear();
		for (int i = 1; i <= 1000; ++i)
			adj[i].clear();

		scanf("%d", &m);

		for (int i = 0; i < m; ++i)
		{
			scanf("%s %s", s[0], s[1]);
			int u = getID(0), v = getID(1);
			adj[u].push_back(v);
			edge[i] = pii(u, v);
		}

		n1 = id[0].size(), n2 = id[1].size();
		res = maxMatching();

		for (int i = 0; i < m; ++i)
		{
			if (pairU[edge[i].F] == -1)
				pairU[edge[i].F] = 0, ++res;
			else if (pairV[edge[i].S] == -1)
				pairV[edge[i].S] = 0, ++res;
		}

		printf("Case #%d: %d\n", tt, m - res);
	}
	return 0;
}