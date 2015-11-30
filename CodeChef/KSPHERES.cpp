#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll n, m, c, x, cntu[1111], cntd[1111], nn, cnt[1111];
ll f[1111][1111];

int main()
{
    //freopen("in.txt", "r", stdin);
    cin >> n >> m >> c;
    for (ll i = 0; i < n; ++i)
    {
        cin >> x;
        ++cntu[x];
    }
    for (ll i = 0; i < m; ++i)
    {
        cin >> x;
        ++cntd[x];
    }

    nn = 1;

    for (ll i = 1; i <= c; ++i)
    {
        cnt[nn] = f[0][nn] = (cntd[i]*cntu[i]) % MOD;
        if (f[0][nn]) { f[0][nn] += f[0][nn-1]; f[0][nn] %= MOD; ++nn; }
    }

    --nn;

    for (ll i = 1; i <= c; ++i)
    {
        ll sum = 0;
        for (ll j = 1; j <= nn; ++j)
        {
            sum += (f[i][j] = (f[i-1][j-1] * cnt[j]) % MOD);
            f[i][j] += f[i][j-1];
            f[i][j] %= MOD;
        }

        cout << sum%MOD << ' ';
    }

    return 0;
}
