#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

typedef pair<int, int> pii;
char mp[1111][1111];
int res[1111][1111];
int n, m, k;

bool valid(int x, int y)
{
    return (x > 0 && y > 0 && x <= n && y <= m);
}

int calc(int x, int y)
{
    if (mp[x][y] == '#')
        return res[x][y];
    if (mp[x][y] == '*')
        return 0;

    vector<pii> v;
    queue<pii> q;
    v.push_back(pii(x,y));
    q.push(pii(x,y));
    mp[x][y] = '#';
    int cnt = 0;

    while (!q.empty())
    {
        pii u = q.front(); q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = u.F + dx[i];
            int ny = u.S + dy[i];
            if (valid(nx, ny))
            {
                if (mp[nx][ny] == '.')
                    q.push(pii(nx, ny)), v.push_back(pii(nx, ny)), mp[nx][ny] = '#';
                else if (mp[nx][ny] == '*')
                    ++cnt;
            }
        }
    }

    for (int i = 0; i < v.size(); ++i)
        res[v[i].F][v[i].S] = cnt;

    return cnt;
}

int main()
{
    memset(res, 0, sizeof(res));
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%s", mp[i] + 1);
    for (int i = 0, x, y; i < k; ++i)
    {
        scanf("%d %d", &x, &y);
        printf("%d\n", calc(x, y));
    }
    return 0;
}
