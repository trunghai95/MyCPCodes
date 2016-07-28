#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Edge {
	int id, u, v;
	ll w;

	Edge(int i, int x, int y, ll z): id(i), u(x), v(y), w(z) {}
};

int n, m, s, t, rem, dfs_low[1010], dfs_num[1010], dfs_cnt;
vector<Edge> adj[1010], e;
ll mn = INF;
int res1, res2, parent[1010];
vector<int> path;
bool ff[1010];

bool dfs(int u)
{
	dfs_low[u] = dfs_num[u] = ++dfs_cnt;

	for (int i = 0; i < (int)adj[u].size(); ++i)
	if (adj[u][i].id != rem)
	{
		int v = adj[u][i].v;
		if (!dfs_num[adj[u][i].v])
		{
			// cout << "a " << u << ' ' << v << '\n';
			parent[v] = adj[u][i].id;

			dfs(v);

			if (ff[v])
				ff[u] = true;

			if (ff[v] && dfs_low[v] > dfs_num[u] && adj[u][i].w + e[rem].w < mn)
			{
				// cout << rem << " - " << u << ' ' << v << ' ' << dfs_num[u] << ' ' << dfs_low[v] << '\n';
				mn = adj[u][i].w + e[rem].w, res1 = adj[u][i].id, res2 = rem;
			}

			// cout << "a " << u << ' ' << v << ' ' << dfs_num[v] << '\n';
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if (adj[u][i].id != parent[u])
		{
			// cout << "b " << u << ' ' << v << '\n';
			// cout << "b " << u << ' ' << v << ' ' << dfs_num[v] << '\n';
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
			// cout << v << ' ' << ff[v] << '\n';
			if (ff[v])
				ff[u] = true;
		}
	}

	return ff[u];
}

void find_path()
{
	memset(parent, 0, sizeof(parent));
	queue<int> q;
	q.push(s);
	parent[s] = -1;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		if (u == t)
			break;

		for (int i = 0; i < (int)adj[u].size(); ++i)
		{
			int v = adj[u][i].v;
			if (!parent[v])
			{
				q.push(v);
				parent[v] = u;
			}
		}
	}

	int x = t;
	while (x != s)
	{
		int u = min(x, parent[x]);
		int v = max(x, parent[x]);
		for (int i = 1; i <= m; ++i)
		if (e[i].u == u && e[i].v == v)
		{
			path.push_back(i);
			break;
		}

		x = parent[x];
	}
}

int main()
{
	scanf("%d %d %d %d", &n, &m, &s, &t);

	e.push_back(Edge(0,0,0,0));

	for (int i = 1, x, y, z; i <= m; ++i)
	{
		scanf("%d %d %d", &x, &y, &z);
		adj[x].push_back(Edge(i, x, y, z));
		adj[y].push_back(Edge(i, y, x, z));
		e.push_back(Edge(i, min(x,y), max(x,y), z));
	}

	ff[t] = true;
	if (!dfs(s))
	{
		printf("0\n0");
		return 0;
	}

	find_path();

	for (int i = 0; i < (int)path.size(); ++i)
	{
		// cout << "AAA\n";
		rem = path[i];
		memset(dfs_low, 0, sizeof(dfs_low));
		memset(dfs_num, 0, sizeof(dfs_num));
		memset(parent, 0, sizeof(parent));
		memset(ff, 0, sizeof(ff));
		ff[t] = true;
		dfs_cnt = 0;
		dfs(s);
	}

	if (!res1)
		printf("-1");
	else if (!res2)
		printf("%lld\n1\n%d", mn, res1);
	else
		printf("%lld\n2\n%d %d", mn, res1, res2);

	return 0;
}