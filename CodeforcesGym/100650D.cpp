#include <bits/stdc++.h>

using namespace std;

#define PAWN 1
#define QUEEN 2
#define KNIGHT 3

int n, m;
int mp[1111][1111];

int main()
{
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    int tt = 0;
    while (++tt)
    {
        cin >> n >> m;
        if (!n && !m) return 0;

        memset(mp, 0, sizeof(mp));
        int k, x, y;
        cin >> k;
        for (int i = 0; i < k; ++i)
        {
            cin >> x >> y;
            mp[x][y] = QUEEN;
        }
        cin >> k;
        for (int i = 0; i < k; ++i)
        {
            cin >> x >> y;
            mp[x][y] = KNIGHT;
        }
        cin >> k;
        for (int i = 0; i < k; ++i)
        {
            cin >> x >> y;
            mp[x][y] = PAWN;
        }

        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (mp[i][j] <= PAWN) continue;

            if (mp[i][j] == KNIGHT)
            {
                if (!mp[i-2][j-1]) mp[i-2][j-1] = -1;
                if (!mp[i-1][j-2]) mp[i-1][j-2] = -1;
                if (!mp[i+1][j-2]) mp[i+1][j-2] = -1;
                if (!mp[i+2][j-1]) mp[i+2][j-1] = -1;
                if (!mp[i+1][j+2]) mp[i+1][j+2] = -1;
                if (!mp[i+2][j+1]) mp[i+2][j+1] = -1;
                if (!mp[i-1][j+2]) mp[i-1][j+2] = -1;
                if (!mp[i-2][j+1]) mp[i-2][j+1] = -1;
            }
            else
            {
                for (int k = 1; k <= max(m,n); ++k)
                {
                    if (i+k <= n && j+k <= m && mp[i+k][j+k] <= 0)
                        mp[i+k][j+k] = -1;
                    else break;
                }
                for (int k = 1; k <= max(m,n); ++k)
                {
                    if (i+k <= n && j-k >= 1 && mp[i+k][j-k] <= 0)
                        mp[i+k][j-k] = -1;
                    else break;
                }
                for (int k = 1; k <= max(m,n); ++k)
                {
                    if (i-k >= 1 && j+k <= m && mp[i-k][j+k] <= 0)
                        mp[i-k][j+k] = -1;
                    else break;
                }
                for (int k = 1; k <= max(m,n); ++k)
                {
                    if (i-k >= 1 && j-k >= 0 && mp[i-k][j-k] <= 0)
                        mp[i-k][j-k] = -1;
                    else break;
                }
                for (int k = 1; k <= m; ++k)
                {
                    if (j+k <= m && mp[i][j+k] <= 0)
                        mp[i][j+k] = -1;
                    else break;
                }
                for (int k = 1; k <= m; ++k)
                {
                    if (j-k >= 0 && mp[i][j-k] <= 0)
                        mp[i][j-k] = -1;
                    else break;
                }
                for (int k = 1; k <= n; ++k)
                {
                    if (i+k <= n && mp[i+k][j] <= 0)
                        mp[i+k][j] = -1;
                    else break;
                }
                for (int k = 1; k <= n; ++k)
                {
                    if (i-k >= 0 && mp[i-k][j] <= 0)
                        mp[i-k][j] = -1;
                    else break;
                }
            }
        }

        int res = 0;
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            res += (mp[i][j] == 0);
        }
        cout << "Board " << tt << " has " << res << " safe squares.\n";
    }
    return 0;
}
