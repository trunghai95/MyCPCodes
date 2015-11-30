#include <bits/stdc++.h>

using namespace std;

int r, s, p;
double rr, rs, rp, dp[101][101][101];

int main()
{
    scanf("%d %d %d", &r, &s, &p);
    rr = rs = rp = 0.0;
    memset(dp, 0, sizeof(dp));
    dp[r][s][p] = 1;
    for (int sum = r + s + p; sum > 0; --sum)
    for (int xr = r; xr >= 0; --xr)
    for (int xs = s; xs >= 0; --xs)
    {
        int xp = sum - xs - xr;
        if (xp < 0 || xp > p) continue;
        if (((xr == 0) + (xs == 0) + (xp == 0)) >= 2) continue;
        int tmp = xr*xs + xs*xp + xp*xr;
        if (xr) dp[xr-1][xs][xp] += dp[xr][xs][xp]*xr*xp*1.0/tmp;
        if (xs) dp[xr][xs-1][xp] += dp[xr][xs][xp]*xs*xr*1.0/tmp;
        if (xp) dp[xr][xs][xp-1] += dp[xr][xs][xp]*xp*xs*1.0/tmp;
    }

    for (int i = 1; i <= r; ++i) rr += dp[i][0][0];
    for (int i = 1; i <= s; ++i) rs += dp[0][i][0];
    for (int i = 1; i <= p; ++i) rp += dp[0][0][i];
    printf("%.12lf %.12lf %.12lf", rr, rs, rp);
    return 0;
}
