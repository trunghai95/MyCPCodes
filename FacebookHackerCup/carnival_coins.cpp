#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int test, n, k;
ld p;

int main()
{
    //freopen("D:\\carnival_coins.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> test;
    for (int tt = 1; tt <= test; ++tt)
    {
        cin >> n >> k >> p;
        int mx = n/k;
        ld res = 0;
        if (mx == 0)
        {
            printf("Case #%d: 0.000000000\n", tt);
            continue;
        }

        for (int part = 1; part <= mx; ++part)
        {
            int onePart = n / part;

            ld tmp = 0, tmp2 = 0;
            int remain = n % part;

            ld x = pow(-p + 1, onePart);
            for (int i = 1; i < k; ++i)
                x = x * p / (-p + 1) * (onePart - i + 1) / i;
            for (int i = k; i <= onePart; ++i)
                x = x * p / (-p + 1) * (onePart - i + 1) / i, tmp += x;

            tmp2 = tmp * (part - remain);
            ++onePart;
            tmp = 0;

            x = pow(-p + 1, onePart);
            for (int i = 1; i < k; ++i)
                x = x * p / (-p + 1) * (onePart - i + 1) / i;
            for (int i = k; i <= onePart; ++i)
                x = x * p / (-p + 1) * (onePart - i + 1) / i, tmp += x;

            tmp2 += tmp * remain;

            res = max(res, tmp2);
        }

        printf("Case #%d: %.9lf\n", tt, (double)res);
    }
    return 0;
}
