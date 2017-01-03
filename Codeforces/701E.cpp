#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;
bool ck[200010];
vector<int> adj[200010];
ll res;

int dfs(int u, int v = -1)
{
    int ret = (ck[u] == true);
    for (int i = 0; i < (int)adj[u].size(); ++i)
    if (adj[u][i] != v)
    {
        int tmp = dfs(adj[u][i], u);
        ret += tmp;
        res += min(tmp, k*2 - tmp);
    }

    return ret;
}

int main()
{
    scanf("%d %d", &n, &k);

    for (int i = 0, u; i < k*2; ++i)
    {
        scanf("%d", &u);
        ck[u] = true;
    }

    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    printf("%lld\n", res);

    return 0;
}
