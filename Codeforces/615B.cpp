#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<int> adj[100001];
ll f[100001], deg[100001];
ll res;

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 0, u, v; i < m; ++i)
    {
        scanf("%d %d", &u, &v);
        if (u > v) swap(u,v);
        adj[v].push_back(u);
        ++deg[u], ++deg[v];
    }

    for (int i = 1; i <= n; ++i)
    {
        f[i] = 0;
        for (int j = 0; j < adj[i].size(); ++j)
            f[i] = max(f[i], f[adj[i][j]]);
        ++f[i];
        res = max(res, f[i] * deg[i]);
    }

    printf("%lld", res);
    return 0;
}
