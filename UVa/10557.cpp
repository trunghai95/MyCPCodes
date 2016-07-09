#include <bits/stdc++.h>

using namespace std;

const int INF = 1e6;

struct Edge
{
	int u, v, w;
	Edge(int uu, int vv, int ww): u(uu), v(vv), w(ww) {}
};

int n, dist[111], val[111];
vector<Edge> e;
vector<int> adj[111];
bool ck[111];

bool bfs(int u)
{
	queue<int> q;
	bool c[111];
	memset(c, 0, sizeof(c));
	q.push(u);
	c[u] = true;

	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		if (v == n)
			return true;
		for (int i = 0; i < (int)adj[v].size(); ++i)
		if (!c[adj[v][i]])
		{
			c[adj[v][i]] = true;
			q.push(adj[v][i]);
		}
	}
	return false;
}

int main()
{
	while (scanf("%d", &n))
	{
		if (n == -1)
			return 0;

		e.clear();

		for (int i = 1, cnt, v; i <= n; ++i)
		{
			dist[i] = INF;
			adj[i].clear();
			scanf("%d %d", val+i, &cnt);
			for (int j = 0; j < cnt; ++j)
			{
				scanf("%d", &v);
				e.push_back(Edge(i, v, 0));
				adj[i].push_back(v);
			}
		}

		for (int i = 0; i < (int)e.size(); ++i)
			e[i].w = -val[e[i].v];

		dist[1] = 0;

		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < (int)e.size(); ++j)
			{
				int u = e[j].u, v = e[j].v;
				if (dist[u] + e[j].w < min(100, dist[v]))
					dist[v] = dist[u] + e[j].w;
			}
		}

		// for (int i = 1; i <= n; ++i)
		// 	cout << dist[i] << ' ';
		// cout << '\n';

		if (dist[n] < 100)
			printf("winnable\n");
		else
		{
			memset(ck, 0, sizeof(ck));
			for (int j = 0; j < (int)e.size(); ++j)
			{
				int u = e[j].u, v = e[j].v;
				if (dist[u] + e[j].w < min(100, dist[v]))
					ck[u] = ck[v] = true;
			}

			bool f = false;
			for (int i = 1; !f && i <= n; ++i)
			if (ck[i] && bfs(i))
				f = true;

			if (f)
				printf("winnable\n");
			else 
				printf("hopeless\n");
		}
	}
	return 0;
}