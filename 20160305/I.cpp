#include <bits/stdc++.h>

using namespace std;

int test, m, n;
map<string, int> mp;
char s[2][100];
vector<int> adj[3001];

int getID(int p)
{
	string str(s[p]);
	map<string, int>::iterator it = mp.find(str);

	if (it == mp.end())
		return (mp[str] = mp.size());

	return (*it).second;
}

bool bfs(int p)
{
	int dist[3010];
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(p);
	dist[p] = 0;

	while (!q.empty())
	{
		int u = q.front(); q.pop();
		if (dist[u] == 7)
			return 0;

		for (int i = 0; i < adj[u].size(); ++i)
		if (dist[adj[u][i]] == -1)
		{
			q.push(adj[u][i]);
			dist[adj[u][i]] = dist[u] + 1;
		}
	}

	return 1;
}

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		for (int i = 1; i <= 3000; ++i)
			adj[i].clear();
		mp.clear();
		scanf("%d", &m);
		for (int i = 0; i < m; ++i)
		{
			scanf("%s %s", s[0], s[1]);
			int id0 = getID(0), id1 = getID(1);
			adj[id0].push_back(id1);
			adj[id1].push_back(id0);
		}

		n = mp.size();
		int mn = n / 20, res = 0;

		for (int i = 1; i <= n; ++i)
		if (!bfs(i))
		{
			++res;
			if (res > mn)
				break;
		}

		if (res > mn)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}