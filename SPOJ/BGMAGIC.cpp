#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

ll a[2001][2001], res;
int n, m;

ll Try(int d1, int d2)
{
    ll res = 0;
    int d[2][2] = { { d1, d2 }, { 1 - d2, 1 - d1 } };
    for (int j = 1; j <= n; ++j)
    for (int i = 1; i <= m; ++i)
    {
        if (a[j][i] > 0)
        {
            if ((a[j][i] & 1) == d[j&1][i&1] && a[j][i] > abs(a[j][i-1]) && a[j][i] > abs(a[j-1][i]))
                res += a[j][i];
            else return INF;
        }
        else
        {
            a[j][i] = - max(abs(a[j][i-1]), abs(a[j-1][i])) - 1;
            if ((a[j][i] & 1) != d[j&1][i&1]) --a[j][i];
            res -= a[j][i];
        }
    }

    return res;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
    {
        scanf("%lld", &a[i][j]);
    }

    if (n == 1)
    {
        res = 0;
        for (int i = 1; i <= m && res >= 0; ++i)
        {
            if (a[1][i])
            {
                if (a[1][i] > a[1][i-1])
                    res += a[1][i];
                else res = -1;
            }
            else res += (a[1][i] = a[1][i-1] + 1);
        }

        printf("%lld", res);
        return 0;
    }

    if (m == 1)
    {
        res = 0;
        for (int i = 1; i <= n && res >= 0; ++i)
        {
            if (a[i][1])
            {
                if (a[i][1] > a[i-1][1])
                    res += a[i][1];
                else res = -1;
            }
            else res += (a[i][1] = a[i-1][1] + 1);
        }

        printf("%lld", res);
        return 0;
    }

    res = min(Try(0,0), min(Try(0,1), min(Try(1,0), Try(1,1))));
    if (res != INF)
        printf("%lld", res);
    else printf("-1");
    return 0;
}
