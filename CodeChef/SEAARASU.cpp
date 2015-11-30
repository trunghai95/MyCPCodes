#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5;
int n, test;
ll a[MAXN];

ll gcd(ll x, ll y)
{
    while (x && y)
    {
        (x > y) ? (x %= y) : (y %= x);
    }

    return x + y;
}

int main()
{
    scanf("%d", &test);

    while (test--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%lld", a + i);

        ll res = a[0];
        for (int i = 1; i < n; ++i)
            res = gcd(res, a[i]);

        res *= n;
        printf("%lld\n", res);
    }
    return 0;
}
