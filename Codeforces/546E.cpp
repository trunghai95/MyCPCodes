#include <bits/stdc++.h>

using namespace std;

int e[210][210], a[110], b[110], n, m, s, t;
vector<int> adj[210];

int maxflow()
{
    int prev[210];
    bool ck[210];
    int res = 0;

    while (1)
    {
        memset(ck, 0, sizeof(ck));
        memset(prev, -1, sizeof(prev));
        queue<int> q;
        ck[s] = 1;
        q.push(s);

        while (!q.empty())
        {
            int u = q.front(); q.pop();
            if (u == t) break;

            for (int i = 0; i <= t; ++i)
            if (!ck[i] && e[u][i] > 0)
                ck[i] = 1, prev[i] = u, q.push(i);
        }

        if (prev[t] == -1) break;

        int tmp = t;
        int f = 2e9;

        while (prev[tmp] != -1)
        {
            f = min(f, e[prev[tmp]][tmp]);
            tmp = prev[tmp];
        }

        tmp = t;
        while (prev[tmp] != -1)
        {
            e[prev[tmp]][tmp] -= f;
            e[tmp][prev[tmp]] += f;
            tmp = prev[tmp];
        }

        res += f;
    }

    return res;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    s = 0;
    t = (n << 1) | 1;

    int suma = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        suma += a[i];
        e[s][i] = a[i];
        e[i][n+i] = 2e9;
    }

    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        e[n+i][t] = b[i];
        sum += b[i];
    }

    for (int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(n+v);
        adj[n+v].push_back(u);
        e[u][n+v] = e[v][n+u] = 2e9;
    }

    if (suma != sum || maxflow() != sum)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << e[n+j][i] << ' ';

        cout << '\n';
    }

    return 0;
}
