#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, a[200010];

int main()
{
    scanf("%lld", &n);
    ll minn = 1e9;
    for (ll i = 0; i < n; ++i)
    {
        scanf("%d", a+i);
        minn = min(minn, a[i]);
    }

    ll res = 0;
    ll tmp = 0;

    for (ll i = 0; i < n; ++i)
    {
        if (a[i] > minn)
        {
            ++tmp;
            res = max(res, tmp);
        }
        else
            tmp = 0;
    }

    tmp = 0;
    ll i;
    for (i = 0; i < n && a[i] > minn; ++i)
        ++tmp;
    if (i < n)
        for (i = n - 1; i >= 0 && a[i] > minn; --i)
        ++tmp;

    res = max(res, tmp);

    res += minn*n;
    printf("%lld", res);
    return 0;
}
