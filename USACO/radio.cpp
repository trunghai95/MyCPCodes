#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

#define x first
#define y second

int n, m, dp[2000][2000];
char s[2000];
pii pos[2][2000];

int dist(int i, int j)
{
    return (pos[0][i].x - pos[1][j].x)*(pos[0][i].x - pos[1][j].x) + (pos[0][i].y - pos[1][j].y)*(pos[0][i].y - pos[1][j].y);
}

int main()
{
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
    cin >> n >> m >> pos[0][0].x >> pos[0][0].y >> pos[1][0].x >> pos[1][0].y;

    for (int i = 0; i < 2; ++i)
    {
        cin >> (s + 1);
        int len = strlen(s + 1);
        for (int j = 1; j <= len; ++j)
        {
            pos[i][j] = pos[i][j-1];
            if (s[j] == 'N')
                pos[i][j].y = pos[i][j-1].y + 1;
            else if (s[j] == 'S')
                pos[i][j].y = pos[i][j-1].y - 1;
            else if (s[j] == 'E')
                pos[i][j].x = pos[i][j-1].x + 1;
            else
                pos[i][j].x = pos[i][j-1].x - 1;
        }
    }

    for (int i = 1; i <= n; ++i)
        dp[i][0] = dp[i-1][0] + dist(i,0);
    for (int i = 1; i <= m; ++i)
        dp[0][i] = dp[0][i-1] + dist(0,i);


    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
    {
        dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + dist(i, j);
    }

    cout << dp[n][m];

    return 0;
}
