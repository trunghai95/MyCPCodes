#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
    ll n, b;
    ll cur = 0, res = 0;
    scanf("%lld", &n);

    for (ll i = 0; i < n; ++i)
    {
        scanf("%lld", &b);
        res += abs(b - cur);
        cur = b;
    }

    printf("%lld", res);

    return 0;
}
