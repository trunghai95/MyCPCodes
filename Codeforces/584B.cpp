#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll n;

ll p(ll x, ll y)
{
    if (y == 0) return 1;
    if (y == 1) return x;

    ll tmp = p(x,y/2) % MOD;

    if (y&1) return (tmp*tmp*x) % MOD;
    return (tmp*tmp) % MOD;
}

int main()
{
    cin >> n;
    ll tmp = p(3,3*n) - p(7,n);
    while (tmp < 0) tmp += MOD;
    cout << tmp % MOD;
    return 0;
}
