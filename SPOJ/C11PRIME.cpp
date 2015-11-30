#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37};

ll multiply(ll a, ll b, ll mod) // O(1) for (a*b)%m
{
    a %= mod; b %= mod;
    long double res = a;
    res *= b;
    ll c = (ll)(res / mod);
    a = (a*b - c*mod) % mod;
    if (a < 0) a += mod;
    return a;
}

ll power(ll a, ll b, ll mod)
{
    ll ans = 1;
    while(b)
    {
        if (b&1) ans = multiply(ans, a, mod);
        a = multiply(a, a, mod);
        b >>= 1;
    }
    return ans;
}

bool Miller(ll p)
{
    if (p < 2) return false;
    if (p != 2 && !(p&1)) return false;

    int cnt = 0;
    ll s = p - 1;
    while (!(s&1))
    {
        s >>= 1;
        ++cnt;
    }
    int sz = sizeof(prime) / sizeof(int);
    for(int i = 0; i < sz; ++i)
    {
        ll a = prime[i];
        if (a >= p) break;
        ll x = power(a, s, p);
        if (x == 1 || x == p-1) continue;
        int flag = 0;
        for(int i = 1; i < cnt; i++)
        {
            x = multiply(x, x, p);
            if(x == 1) return false;
            if(x == p-1)
            {
                flag = 1;
                break;
            }
        }
        if (!flag) return false;
    }
    return true;
}

ll n;

int main()
{
    cin >> n;

    for (ll q = 2; q <= 59; ++q)
    {
        ll p1 = (int)floor(pow(1.0*n, 1.0/q));
        ll p2 = p1+1;

        ll x1 = 1, x2 = 1;
        for (int i = 1; i <= q; ++i)
            x1 *= p1, x2 *= p2;

        if (x1 == n && Miller(p1))
        {
            cout << p1 << ' ' << q;
            return 0;
        }

        if (x2 == n && Miller(p2))
        {
            cout << p2 << ' ' << q;
            return 0;
        }
    }

    cout << 0;
    return 0;
}
