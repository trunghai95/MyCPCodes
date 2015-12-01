#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, k, s[111111];

int main()
{
    scanf("%lld %lld", &n, &k);

    for (ll i = 0; i < n; ++i)
        scanf("%lld", &s[i]);

    if (k >= n)
    {
        printf("%lld", s[n-1]);
        return 0;
    }

    ll nn = n - k;
    ll res = s[n-1];

    for (ll i = 0; i < nn; ++i)
    {
        res = max(res, s[i] + s[nn*2 - i - 1]);
    }

    printf("%lld", res);
    return 0;
}
