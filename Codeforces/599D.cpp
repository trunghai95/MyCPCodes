#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

ll stub(ll a, ll t)
{

    return a*(a+1)*(a*2 + t*3 + 1) / 6;
}

vector<pii> res;

int main()
{
    ll n;
    scanf("%lld", &n);

    ll a = 1;

    while (1)
    {
        ll t = (n*6 - (a*a + a)*(2*a + 1)) / (a*a + a) / 3;
        if (t < 0) break;

        if (stub(a, t) == n)
            res.push_back(pii(a, a+t));

        ++a;
    }

    if (res.empty())
    {
        printf("0");
        return 0;
    }

    int ff = (res.back().first == res.back().second);
    printf("%d\n", res.size()*2 - ff);
    for (int i = 0; i < res.size(); ++i)
        printf("%lld %lld\n", res[i].first, res[i].second);
    if (ff) res.pop_back();
    for (int i = res.size() - 1; i >= 0; --i)
        printf("%lld %lld\n", res[i].second, res[i].first);

    return 0;
}
