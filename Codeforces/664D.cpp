#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

#define F first
#define S second

int n, m, f[100010], cnt[2];
char s[10];
vector<pii> adj[100010];
vector<int> step[2];

int proc(int color)
{
	memset(f, -1, sizeof(f));
	int res = 0;
	
	for (int i = 1; i <= n; ++i)
	if (f[i] == -1)
	{
		vector<int> tmp;
		queue<int> q;
		f[i] = 0;
		q.push(i);
		cnt[0] = cnt[1] = 0;

		while (!q.empty())
		{
			int u = q.front(); q.pop();
			++cnt[f[u]];
			tmp.push_back(u);

			for (int j = 0; j < (int)adj[u].size(); ++j)
			{
				if (f[adj[u][j].F] == -1)
				{
					if (adj[u][j].S == color)
						f[adj[u][j].F] = f[u];
					else
						f[adj[u][j].F] = 1 - f[u];
					q.push(adj[u][j].F);
				}
				else if ((adj[u][j].S == color) != (f[adj[u][j].F] == f[u]))
						return -1;
			}
		}
		int mn = (cnt[0] < cnt[1]) ? 0 : 1;
		for (int j = 0; j < (int)tmp.size(); ++j)
		if (f[tmp[j]] == mn)
			step[color].push_back(tmp[j]);
		res += cnt[mn];
	}

	return res;
}

void printRes(int c)
{
	printf("%d\n", step[c].size());
	for (int i = 0; i < (int)step[c].size(); ++i)
		printf("%d ", step[c][i]);
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0, u, v; i < m; ++i)
	{
		scanf("%d %d %s", &u, &v, s);
		adj[u].push_back(pii(v, s[0] == 'R'));
		adj[v].push_back(pii(u, s[0] == 'R'));
	}

	int a = proc(0), b = proc(1);
	if (a == -1 && b == -1)
		printf("-1");
	else if (a == -1)
		printRes(1);
	else if (b == -1)
		printRes(0);
	else
		printRes(a < b ? 0 : 1);
	return 0;
}