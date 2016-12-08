#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second

int n;
ll t, w;
vector<pll> v;
multiset<ll> ms;

int main() {
    scanf("%d %lld %lld", &n, &t, &w);
    --n;
    ll k = t;

    for (int i = 1; i <= n; ++i) {
        scanf("%lld %lld", &t, &w);
        if (t > k)
            ms.insert(w - t + 1);
        else
            v.push_back(pll(t, w));
    }

    sort(v.begin(), v.end());

    int res = ms.size();

    while (true) {
        if (ms.empty() || *ms.begin() > k) break;
        k -= *ms.begin();
        ms.erase(ms.begin());
        while (!v.empty() && v.back().F > k) {
            ms.insert(v.back().S - v.back().F + 1);
            v.pop_back();
        }
        res = min(res, (int)ms.size());
    }

    printf("%d\n", res + 1);
    return 0;
}
