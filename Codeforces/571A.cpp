#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll a, b, c, l, res, x;

ll f(ll x)
{
    if (x < 0) return 0;
    return (x+1)*(x+2)/2;
}

int main()
{
    scanf("%lld %lld %lld %lld", &a, &b, &c, &l);
    res = (l+1)*(l+2)*(l+3)/6; // (l+3)C3
    for (ll i = 0; i <= l; ++i)
        res -= f(min(a-b-c+i, l-i)) + f(min(b-c-a+i, l-i)) + f(min(c-b-a+i, l-i));
    printf("%lld", res);
    return 0;
}
