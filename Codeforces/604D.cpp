#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;

bool ck[1000000];
ll p, k, cnt;

ll mypow(ll x, ll y)
{
    if (!y)
        return 1;

    ll tmp = mypow(x, y >> 1);
    tmp = (tmp*tmp) % MODD;
    if (y & 1LL)
        return (tmp * x) % MODD;
    else return tmp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> p >> k;

    if (k == 0)
    {
        cout << mypow(p, p-1);
        return 0;
    }

    if (k == 1)
    {
        cout << mypow(p, p);
        return 0;
    }

    for (ll i = 1; i < p; ++i)
    if (!ck[i])
    {
        ++cnt;
        ll x = i;
        while (!ck[x])
        {
            ck[x] = true;
            x = k*x % p;
        }
    }

    cout << mypow(p, cnt);
    return 0;
}
