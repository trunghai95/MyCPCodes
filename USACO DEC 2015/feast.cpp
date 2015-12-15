#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

bool visited[5000001][2];
int t, a, b;

int main()
{
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> t >> a >> b;

    if (t % a == 0 || t % b == 0 || t % (a+b) == 0)
    {
        cout << t;
        return 0;
    }

    queue<pii> q;
    visited[0][0] = true;
    q.push(pii(0,0));
    int res = 0;

    while (!q.empty())
    {
        pii u = q.front(); q.pop();
        res = max(res, u.first);
        if (res == t) break;

        if (u.first + a <= t && !visited[u.first + a][u.second])
        {
            visited[u.first + a][u.second] = true;
            q.push(pii(u.first + a, u.second));
        }

        if (u.first + b <= t && !visited[u.first + b][u.second])
        {
            visited[u.first + b][u.second] = true;
            q.push(pii(u.first + b, u.second));
        }

        if (!u.second && !visited[u.first >> 1][1])
        {
            visited[u.first >> 1][1] = true;
            q.push(pii(u.first >> 1, 1));
        }
    }

    cout << res;
    return 0;
}
