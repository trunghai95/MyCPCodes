#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

struct cmp { bool operator()(pii x, pii y) { return x > y; } };

int n, e, t, m;
vector<pii> adj[101];
int dist[101];

int main()
{
	scanf("%d %d %d %d", &n, &e, &t, &m);

	for (int i = 0, u, v, k; i < m; ++i)
	{
		scanf("%d %d %d", &u, &v, &k);
		adj[v].push_back(pii(u, k));
	}

	memset(dist, -1, sizeof(dist));
	priority_queue<pii, vector<pii>, cmp> q;

	q.push(pii(0, e));

	while (!q.empty())
	{
		pii u = q.top();
		q.pop();
		if (dist[u.S] != -1) continue;
		dist[u.S] = u.F;

		for (int i = 0; i < (int)adj[u.S].size(); ++i)
		if (dist[adj[u.S][i].F] == -1)
		{
			q.push(pii(u.F + adj[u.S][i].S, adj[u.S][i].F));
		}
	}

	int res = 0;
	for (int i = 1; i <= n; ++i)
		res += (dist[i] <= t && dist[i] != -1);

	printf("%d", res);
	return 0;
}