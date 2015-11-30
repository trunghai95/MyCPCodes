#include <bits/stdc++.h>

using namespace std;

int n, m, e[4001][4001];
vector<vector<int> > adj;

struct Node
{
    int a, b, c, t;
    Node(int x, int y, int z): a(x), b(y), c(z) { t = e[0][a] + e[0][b] + e[0][c] - 6; }
    Node(): a(-1), b(-1), c(-1), t(-1) {}
} res;

int main()
{
    cin >> n >> m;
    memset(e,0,sizeof(e));
    adj.assign(n+1,vector<int>());
    for (int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        ++e[u][v];
        ++e[v][u];
        ++e[0][u];
        ++e[0][v];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (e[0][i] < 2) continue;
        for (int j = 0; j < adj[i].size(); ++j)
        for (int k = j+1; k < adj[i].size(); ++k)
        if (e[adj[i][j]][adj[i][k]])
        {
            Node tmp(i,adj[i][j],adj[i][k]);
            if (res.t == -1 || tmp.t < res.t) res = tmp;
        }
    }
    cout << res.t;
    return 0;
}
