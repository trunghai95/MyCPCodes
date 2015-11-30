#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
int n, m, a, b;
char mp[600][600];
int dist[600][600];

int dirX[] = {1,-1,0,0};
int dirY[] = {0,0,1,-1};

bool check(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y] == '.' && dist[x][y] == -1;
}

int main()
{
    cin >> m >> n >> a >> b;
    memset(dist, -1, sizeof(dist));

    for (int i = 1; i <= n; ++i)
        cin >> mp[i] + 1;

    queue<pii> q;
    q.push(pii(1,1));
    dist[1][1] = 0;

    while (!q.empty())
    {
        pii u = q.front(); q.pop();
        for (int i = 0; i < 4; ++i)
        {
            if (check(u.first + dirX[i], u.second + dirY[i]))
            {
                q.push(pii(u.first + dirX[i], u.second + dirY[i]));
                dist[u.first + dirX[i]][u.second + dirY[i]] = dist[u.first][u.second] + 1;
            }
        }
    }

    if (dist[n][m] == -1)
        cout << "IMPOSSIBLE";
    else
        cout << (dist[n][m]/2)*a + (dist[n][m]/2 + dist[n][m]%2)*b;
    return 0;
}
