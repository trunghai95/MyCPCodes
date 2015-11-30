#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Baby
{
    ll v, d, p;
    bool avail;
    Baby(ll v, ll d, ll p): v(v), d(d), p(p), avail(1) {}
};

ll n, res, inVol, outVol;
vector<Baby> baby;
vector<ll> resA;

int main()
{
    //freopen("in.txt", "r", stdin);

    cin >> n;
    for (ll i = 0, v, d, p; i < n; ++i)
    {
        cin >> v >> d >> p;
        baby.push_back(Baby(v, d, p));
    }

    for (ll i = 0; i < baby.size(); ++i)
    {
        if (!baby[i].avail)
            continue;

        ++res;
        resA.push_back(i+1);
        inVol = baby[i].v;
        outVol = 0;

        for (ll j = i + 1; j < baby.size(); ++j)
        {
            if (!baby[j].avail) continue;
            if ((baby[j].p -= inVol + outVol) < 0)
                baby[j].avail = 0, outVol += baby[j].d;
            if (inVol) --inVol;
        }
    }

    cout << res << endl;
    for (ll i = 0; i < resA.size(); ++i)
        cout << resA[i] << ' ';
    return 0;
}
