#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int prime[] = {2,7,61};

ll multiply(ll &a, ll &b, ll &mod) // O(1) for (a*b)%m
{
    a %= mod; b %= mod;
    long double res = a;
    res *= b;
    ll c = (ll)(res / mod);
    a = (a*b - c*mod) % mod;
    if (a < 0) a += mod;
    return a;
}

ll power(ll &a, ll &b, ll &mod)
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

    if (Miller(n))
    {
        cout << 1 << endl << n;
        return 0;
    }

    if (Miller(n-2))
    {
        cout << 2 << endl << "2 " << n-2;
        return 0;
    }

    if (Miller(n-4))
    {
        cout << 3 << endl << "2 2 " << n-4;
        return 0;
    }

    for (ll i = 3; i < n; ++i)
    {
        if (Miller(i) && Miller(n - 3 - i))
        {
            cout << 3 << endl << "3 " << i << ' ' << n - 3 - i;
            return 0;
        }
    }

    return 0;
}
