#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MODD = 1e9 + 7;

int n, test;
ll a[100010], pw2[100010];

void init()
{
    pw2[0] = 1;
    for (int i = 1; i <= 100000; ++i)
        pw2[i] = (pw2[i-1] * 2) % MODD;
}

int main()
{
    init();
    scanf("%d", &test);
    while (test--)
    {
        scanf("%d", &n);
        for (int i = 0; i <= n; ++i)
            scanf("%lld", a+i);
        ll res = (((a[0] * a[1]) % MODD) * pw2[n]) % MODD;
        ll sum = 0;
        for (int i = 2; i <= n; ++i)
            sum = (sum + a[i] * pw2[n-i+1]) % MODD;
        res = (res + (a[0] * sum)) % MODD;

        if (n > 1)
        {
            sum = 0;
            for (int i = n - 1; i > 0; --i)
                sum = (sum + a[i] * pw2[i]) % MODD;
            for (int i = n; i > 1; --i)
            {
                res = (res + sum * a[i]) % MODD;
                sum -= (a[i - 1] * pw2[n - 1]) % MODD;
                while (sum < 0) sum += MODD;
                sum = (sum * 2) % MODD;
            }
        }

        printf("%lld\n", res);
    }
    return 0;
}
