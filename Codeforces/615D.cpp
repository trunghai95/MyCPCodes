//WA

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;

ll cnt[200010], fw[200010], bw[200010];
vector<int> pf;
int m;

ll powMod(ll a, ll b)
{
    if (b == 0)
        return 1LL;

    ll tmp = powMod(a, b/2);
    tmp = (tmp*tmp) % MODD;
    if (b & 1) tmp = (tmp * a) % MODD;
    return tmp;
}

int main()
{
    scanf("%d", &m);

    for (int i = 0, p; i < m; ++i)
    {
        scanf("%d", &p);
        if (!cnt[p]) pf.push_back(p);
        ++cnt[p];
    }

    if (pf.size() == 1)
    {
        ll tmp = (cnt[pf[0]] * (cnt[pf[0]] + 1) / 2) % (MODD - 1);
        ll res = powMod(pf[0], tmp);
        printf("%lld", res);
        return 0;
    }

    fw[0] = cnt[pf[0]] + 1;
    for (int i = 1; i < pf.size(); ++i)
        fw[i] = (fw[i-1] * (cnt[pf[i]] + 1)) % (MODD - 1);

    bw[pf.size() - 1] = cnt[pf.back()] + 1;
    for (int i = pf.size() - 2; i >= 0; --i)
        bw[i] = (bw[i+1] * (cnt[pf[i]] + 1)) % (MODD - 1);

    ll res = 1;

    for (int i = 0; i < pf.size(); ++i)
    {
        ll tmp;
        if (!i)
            tmp = bw[1];
        else if (i == pf.size() - 1)
            tmp = fw[i-1];
        else tmp = (fw[i-1] * bw[i+1]) % (MODD - 1);

        tmp = (tmp * (cnt[pf[i]] * (cnt[pf[i]] + 1) / 2)) % (MODD - 1);
        res = (res * powMod(pf[i], tmp)) % MODD;
    }

    printf("%lld", res);
    return 0;
}
