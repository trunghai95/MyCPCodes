#include <bits/stdc++.h>

using namespace std;

int n, m, dist[100000], res;
vector<vector<int> > adj;
vector<vector<int> > child;
bool cat[100000], f;

int main()
{
    //freopen("in.txt", "r", stdin);
    res = 0;
    cin >> n >> m;
    adj.assign(n, vector<int>());
    child.assign(n, vector<int>());
    memset(cat,0,sizeof(cat));
    memset(dist, -1, sizeof(dist));
    for (int i = 0, tmp; i < n; ++i)
    {
        cin >> tmp;
        cat[i] = tmp;
    }

    for (int i = 1, u, v; i < n; ++i)
    {
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    queue<int> q;
    q.push(0);
    dist[0] = cat[0];

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        if (dist[u] > m) continue;

        f = 1;
        for (int i = 0; i < adj[u].size(); ++i)
        if (dist[adj[u][i]] == -1)
        {
            int v = adj[u][i];
            dist[v] = cat[v]? dist[u] + 1 : 0;
            q.push(v);
            f = 0;
        }

        if (f) ++res;
    }

    cout << res;
    return 0;
}
