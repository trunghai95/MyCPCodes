#include <bits/stdc++.h>

using namespace std;

int n, m, par[100010], h[100010], u, v;
vector<int> child[100010], res;
int mark[100010], want[100010];

void dfs(int u)
{
	for (int i = 0; i < (int)child[u].size(); ++i)
	{
		h[child[u][i]] = h[u] + 1;
		dfs(child[u][i]);
	}
}

bool cmp(int x, int y)
{
	return h[x] > h[y];
}

int main()
{
	memset(par, -1, sizeof(par));
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &u, &v);
		par[v] = u;
		child[u].push_back(v);
	}

	for (int i = 1; i <= n; ++i)
	{
		if (par[i] == -1)
			dfs(i);

		scanf("%d", want+i);
		u = i; v = want[i];
		while (u != v)
		{
			if (mark[u])
			{
				if (want[mark[u]] != v)
				{
					printf("-1");
					return 0;
				}
				break;
			}
			mark[u] = i;
			u = par[u];
		}

		if (!mark[v])
		{
			res.push_back(v);
			mark[v] = i;
		}
		else if (want[mark[v]] != v)
		{
			printf("-1");
			return 0;
		}
	}

	sort(res.begin(), res.end(), cmp);
	printf("%d\n", (int)res.size());
	for (int i = 0; i < (int)res.size(); ++i)
		printf("%d\n", res[i]);
	return 0;
}