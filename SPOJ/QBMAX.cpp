#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
int n, m, a[111][111], f[111][111];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
        f[i][1] = a[i][1];
    }

    for (int j = 2; j <= m; ++j)
    {
        f[0][j-1] = f[n+1][j-1] = -INF;
        for (int i = 1; i <= n; ++i)
            f[i][j] = max(max(f[i-1][j-1], f[i][j-1]), f[i+1][j-1]) + a[i][j];
    }

    int res = -INF;
    for (int i = 1; i <= n; ++i)
        res = max(res, f[i][m]);
    printf("%d", res);
    return 0;
}
