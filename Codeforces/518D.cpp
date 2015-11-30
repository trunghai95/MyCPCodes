#include <bits/stdc++.h>

using namespace std;

int N, T;
double dp[2001][2001], p, res;

int main()
{
    memset(dp,0,sizeof(dp));
    scanf("%d %lf %d", &N, &p, &T);
    dp[0][0] = 1;
    for (int t = 1; t <= T; ++t)
    {
        dp[0][t] = dp[0][t-1]*(1.0-p);
        for (int n = 1; n < N; ++n)
            dp[n][t] = dp[n][t-1]*(1.0-p) + dp[n-1][t-1]*p;
        dp[N][t] = dp[N][t-1] + dp[N-1][t-1]*p;
    }
    for (int i = 1; i <= N; ++i)
        res += i*dp[i][T];
    printf("%.12lf", res);
    return 0;
}
