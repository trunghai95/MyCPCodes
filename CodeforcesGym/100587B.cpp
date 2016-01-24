#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld EPS = 0.0000001;

int test, c[21][21];
ld p, dp[1000000][21], pw[2][21];

void initC()
{
    c[0][0] = 1;
    for (int i = 1; i <= 20; ++i)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j)
            c[i][j] = c[i-1][j] + c[i-1][j-1];
    }
}

int main()
{
    initC();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> test;

    for (int tt = 1; tt <= test; ++tt)
    {
        cin >> p;
        pw[0][0] = pw[1][0] = dp[0][0] = 1;
        for (int i = 1; i <= 20; ++i)
            pw[0][i] = pw[0][i-1] * (1.0 - p),
            pw[1][i] = pw[1][i-1] * p,
            dp[0][i] = 0;

        ld res = 0;
        for (int i = 1; i < 100000; ++i)
        {
            dp[i][0] = dp[i-1][0] * pw[0][20];
            for (int j = 1; j <= 20; ++j)
            {
                dp[i][j] = 0;
                for (int k = 0; k <= j; ++k)
                    dp[i][j] += dp[i-1][k] * pw[1][j-k] * pw[0][20 - j] * c[20-k][j-k];
            }

            ld tmp = dp[i][20] - dp[i-1][20];
            res += (dp[i][20] - dp[i-1][20]) * i;
//            if (i > 1 && tmp < dp[i-1][20] - dp[i-2][20] && tmp < EPS)
//                break;
        }

        printf("Case #%d: %.5lf\n", tt, (double)res);
    }
    return 0;
}
