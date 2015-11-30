#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

#define F first
#define S second

int n, m, p, q, s, t;
int dist[201][201];

int main()
{
    scanf("%d %d %d %d %d %d", &n, &m, &p, &q, &s, &t);

    if ((p+q-s-t)&1)
    {
        printf("-1");
        return 0;
    }

    memset(dist, -1, sizeof(dist));

    for (int i = 0, x, y; i < m; ++i)
    {
        scanf("%d %d", &x, &y);
        dist[x][y] = -2;
    }

    queue<pii> qu;
    dist[p][q] = 0;
    qu.push(pii(p,q));

    while (!qu.empty())
    {
        pii u = qu.front(); qu.pop();
        if (u.F == s && u.S == t)
            break;

        int d = dist[u.F][u.S];

        for (int i = u.F + 1, j = u.S + 1; i <= n && j <= n; ++i, ++j)
        {
            if (dist[i][j] == -2)
                break;

            if (dist[i][j] == -1)
                qu.push(pii(i,j)), dist[i][j] = d + 1;
        }

        for (int i = u.F - 1, j = u.S + 1; i >= 1 && j <= n; --i, ++j)
        {
            if (dist[i][j] == -2)
                break;

            if (dist[i][j] == -1)
                qu.push(pii(i,j)), dist[i][j] = d + 1;
        }

        for (int i = u.F + 1, j = u.S - 1; i <= n && j >= 1; ++i, --j)
        {
            if (dist[i][j] == -2)
                break;

            if (dist[i][j] == -1)
                qu.push(pii(i,j)), dist[i][j] = d + 1;
        }

        for (int i = u.F - 1, j = u.S - 1; i >= 1 && j >= 1; --i, --j)
        {
            if (dist[i][j] == -2)
                break;

            if (dist[i][j] == -1)
                qu.push(pii(i,j)), dist[i][j] = d + 1;
        }
    }

    printf("%d", dist[s][t]);
    return 0;
}
