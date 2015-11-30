#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX = 5e18;

ll t, w, b;

ll gcd(ll a, ll b)
{
    return (a && b) ? ((a > b) ? gcd(a % b, b) : gcd(b % a, a)) : (a + b);
}

int main()
{
    cin >> t >> w >> b;

    ll tu, mau = t;
    ll g = gcd(w, b);
    g = w/g;
    if (MAX/b < g) g = MAX + 1;
    else g *= b;

    ll len = min(w,b);

    if (t < g)
    {
        tu = min(len - 1, t);
    }
    else
    {
        ll tmp = t / g * g;
        tu = tmp/g * len - 1 + min(len, t - tmp + 1);
    }

    g = gcd(tu, mau);
    tu /= g;
    mau /= g;

    cout << tu << '/' << mau;
    return 0;
}
