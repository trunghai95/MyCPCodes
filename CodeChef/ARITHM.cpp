#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ExtendedGcd(ll a, ll b, ll &x, ll &y)
{
    if (a % b == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    ll newx, newy;
    ll ret = ExtendedGcd(b, a % b, newx, newy);

    x = newy;
    y = newx - newy * (a / b);
    return ret;
}

ll gcd(ll x, ll y)
{
    if (!x)
        return y;
    return gcd(y%x, x);
}

int test;
ll n, c, a, b, x, y, g;

int main()
{
    scanf("%d", &test);
    while (test--)
    {
        scanf("%lld %lld", &n, &c);
        if (n == 1)
        {
            printf("Yes\n");
            continue;
        }
        a = n;
        b = n*(n-1)/2;
        g = gcd(a, b);
        if (c % g)
        {
            printf("No\n");
            continue;
        }
        a /= g;
        b /= g;
        c /= g;
        ExtendedGcd(a, b, x, y);
        // cout << a << ' ' << b << ' ' << x << ' ' << y << '\n';
        if ((x > 0 && y > 0) || (x < 0 && y < 0))
        {
            printf("Yes\n");
            continue;
        }
        x *= c;
        y *= c;
        if (y < 0)
            x = -x, y = -y;
        ll r = (1 - x) / b + ((1 - x) % b > 0);
        // cout << x + r*b << ' ' << y - r*a << '\n';
        if (y - r*a > 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}