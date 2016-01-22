#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test, n;
ll sum[100010], p, x;

int main()
{
    //freopen("the_price_is_correct.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt)
    {
        scanf("%d %lld", &n, &p);

        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld", &x);
            sum[i] = sum[i-1] + x;
        }

        ll res = 0;

        for (int i = 1; i <= n; ++i)
        {
            int pos = lower_bound(sum, sum+1+i, sum[i] - p) - sum;
            res += i - pos;
        }

        printf("Case #%d: %lld\n", tt, res);
    }
    return 0;
}
