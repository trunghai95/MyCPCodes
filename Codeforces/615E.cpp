#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

ll binsearch()
{
    ll l = 0;
    ll r = 1500000000;
    while (l < r - 1)
    {
        ll m = (l + r) / 2;
        if (m*(m+1)*3 <= n)
            l = m;
        else r = m - 1;
    }

    if (r*(r+1)*3 <= n)
        return r;
    return l;
}

int main()
{
    cin >> n;
    ll k = binsearch();
    n -= k*(k+1)*3;
    ++k;
    ll x = (k - 1) * 2;
    ll y = 0;

    if (n == 0)
    {
        cout << x << ' ' << y;
        return 0;
    }

    int num = 1;
    while (n >= k) ++num, n -= k;

    if (num == 1)
    {
        x += 1;
        y += 2;
        if (n == 1)
        {
            cout << x << ' ' << y;
            return 0;
        }
        x -= (n - 1);
        y += (n - 1) * 2;
        cout << x << ' ' << y;
        return 0;
    }

    if (num == 2)
    {
        x = k - 2*n;
        y = k*2;
        cout << x << ' ' << y;
        return 0;
    }

    if (num == 3)
    {
        x = -k - n;
        y = k*2 - n*2;
        cout << x << ' ' << y;
        return 0;
    }

    if (num == 4)
    {
        x = -k*2 + n;
        y = -n*2;
        cout << x << ' ' << y;
        return 0;
    }

    if (num == 5)
    {
        x = -k + n*2;
        y = -k*2;
        cout << x << ' ' << y;
        return 0;
    }

    x = k + n;
    y = -k*2 + n*2;
    cout << x << ' ' << y;

    return 0;
}
