#include <bits/stdc++.h>

using namespace std;

int n, m, per[200010], lab[200010], cntcc;
vector<int> adj[200010], conCom[200010];

struct cmp
{
	bool operator()(int x, int y)
	{
		if (conCom[x].size() == conCom[y].size())
			return x < y;
		return conCom[x].size() > conCom[y].size();
	}
};

struct cmpInt
{
	bool operator()(int x, int y) { return x > y; }
};

int main()
{
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	priority_queue<int, vector<int>, cmpInt> availLab;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		availLab.push(i);

	memset(lab, -1, sizeof(lab));

	for (int i = 0, u, v; i < m; ++i)
	{
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i)
		scanf("%d", per+i);

	for (int i = n; i > 0; --i)
	{
		int u = per[i];
		set<int, cmp> st;

		for (int j = 0; j < adj[u].size(); ++j)
		if (lab[adj[u][j]] != -1)
			st.insert(lab[adj[u][j]]);

		if (st.empty())
		{
			int tmp = availLab.top();
			availLab.pop();
			lab[u] = tmp;
			conCom[tmp].push_back(u);
			++cntcc;
		}
		else
		{
			set<int, cmp>::iterator it = st.begin();
			++it;
			while (it != st.end())
			{
				while (!conCom[*it].empty())
				{
					lab[conCom[*it].back()] = *st.begin();
					conCom[*st.begin()].push_back(conCom[*it].back());
					conCom[*it].pop_back();
				}
				availLab.push(*it);
				++it;
				--cntcc;
			}
			lab[u] = *st.begin();
			conCom[*st.begin()].push_back(u);
		}

		per[i] = cntcc;
	}

	for (int i = 1; i <= n; ++i)
	if (per[i] == 1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}