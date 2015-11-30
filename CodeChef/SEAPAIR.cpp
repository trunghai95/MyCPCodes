#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll MODD = 1e9 + 7;

int test, k, n;

int main()
{
//    freopen("in.txt", "r", stdin);

    ll a = 1;
    for (int i = 1; i <= 100; ++i)
        a = (a*10) % MODD;
    a = (a + 1) % MODD;
    scanf("%d", &test);
    while (test--)
    {
        scanf("%d %d", &n, &k);

        vector<pll> p;
        ll x, d;
        for (int i = 0; i < n; ++i)
        {
            scanf("%lld %lld", &x, &d);
            ll lef = d*x;
            ll rig = d*x + x - 1;
            p.push_back(pll(lef, 0));
            p.push_back(pll(rig, 1));
        }

        if (n == k)
        {
            printf("%lld\n", a);
            continue;
        }

        sort(p.begin(), p.end());
        int cnt = 0;
        ll res = 0;
        ll lef = -1, rig = -1;

        for (int i = 0; i < p.size(); ++i)
        {
            if (p[i].second)
                --cnt;
            else ++cnt;

            if (cnt >= n - k)
            {
                if (lef == -1)
                    lef = p[i].first;
                rig = p[i+1].first;
            }
            else
            {
                if (lef != -1 && rig != -1)
                    res = (res + rig - lef + 1) % MODD;
                lef = rig = -1;
            }
        }

        if (rig != -1 && lef != -1)
            res = (res + rig - lef + 1) % MODD;

        printf("%lld\n", res);
    }
    return 0;
}
