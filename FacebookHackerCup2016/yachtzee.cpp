#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll a, b, c[100010], preSum[100010];
int test, n;

int main()
{
    //freopen("yachtzee.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt)
    {
        scanf("%d %lld %lld %lld", &n, &a, &b, c+1);
        preSum[1] = c[1];

        for (int i = 2; i <= n; ++i)
            scanf("%lld", c+i), preSum[i] = preSum[i-1] + c[i];

        int na, ma, nb, mb;
        ld sum = 0, sumc = 0, m = 1.0/(b - a);
        na = a / preSum[n];
        nb = b / preSum[n];
        ma = lower_bound(preSum+1, preSum+1+n, a % preSum[n] + 1) - preSum;
        mb = lower_bound(preSum+1, preSum+1+n, b % preSum[n] + 1) - preSum;
        ll aa = a - na * preSum[n] - preSum[ma - 1];
        ll bb = b - nb * preSum[n] - preSum[mb - 1];

        for (int i = 1; i <= n; ++i)
            sumc += 0.5 * m * c[i]*c[i];

        if (na != nb)
        {
            sum += sumc * (nb - na - 1);
            sum += 0.5 * m * (c[ma]*c[ma] - aa*aa);
            sum += 0.5 * m * bb*bb;

            for (int i = ma + 1; i <= n; ++i)
                sum += 0.5 * m * c[i]*c[i];
            for (int i = 1; i < mb; ++i)
                sum += 0.5 * m * c[i]*c[i];
        }
        else
        {
            for (int i = ma + 1; i < mb; ++i)
                sum += 0.5 * m * c[i]*c[i];

            if (ma == mb)
                sum += 0.5 * m * (bb*bb - aa*aa);
            else
            {
                sum += 0.5 * m * (c[ma]*c[ma] - aa*aa);
                sum += 0.5 * m * bb*bb;
            }
        }

        printf("Case #%d: %.9lf\n", tt, (double)sum);
    }
    return 0;
}
