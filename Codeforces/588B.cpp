#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, x;
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

int main()
{
    cin >> n;
    x = 1;
    ll i = 2;
    while (n > 1 && !Miller(n))
    {
        if (n % i == 0)
            x *= i;

        while (n % i == 0)
            n /= i;

        ++i;
    }

    if (n > 1) x *= n;
    cout << x;
    return 0;
}
