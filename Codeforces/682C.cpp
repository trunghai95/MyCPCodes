#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, ll> pil;

struct Node
{
	int cnt;
	ll val;
	vector<pil> child;
	vector<pil> adj;
	Node(): cnt(0), val(0) {}
};

Node node[100010];
int n, p, res;
ll c;

void dfs1(int u, int v = -1)
{
	node[u].cnt = 1;
	for (int i = 0; i < (int)node[u].adj.size(); ++i)
	if (node[u].adj[i].first != v)
	{
		node[u].child.push_back(node[u].adj[i]);
		dfs1(node[u].adj[i].first, u);
		node[u].cnt += node[node[u].adj[i].first].cnt;
	}
}

void dfs2(int u, ll sum = 0)
{
	if (sum > node[u].val || node[u].val < 0)
	{
		res += node[u].cnt;
		return;
	}

	for (int i = 0; i < (int)node[u].child.size(); ++i)
		dfs2(node[u].child[i].first, max(sum, 0LL) + node[u].child[i].second);
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%lld", &node[i].val);

	for (int i = 2; i <= n; ++i)
	{
		scanf("%d %lld", &p, &c);
		node[i].adj.push_back(pil(p, c));
		node[p].adj.push_back(pil(i, c));
	}

	dfs1(1);
	dfs2(1);

	printf("%d", res);
	return 0;
}