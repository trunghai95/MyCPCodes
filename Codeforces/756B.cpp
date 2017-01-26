#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second

const int MAXN = 100000;
const ll INF = 1e18;
int n;
ll t;
vector<pll> v;

int main() {
    scanf("%d", &n);

    v.push_back(pll(-INF, 0));

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &t);

        ll res = v.back().S + 20;
        int p = lower_bound(v.begin(), v.end(), pll(t - 89, -INF)) - v.begin();
        if (p < (int)v.size()) {
            res = min(res, v[p-1].S + 50);
        }

        p = lower_bound(v.begin(), v.end(), pll(t - 1439, -INF)) - v.begin();
        if (p < (int)v.size()) {
            res = min(res, v[p-1].S + 120);
        }

        printf("%lld\n", res - v.back().S);
        v.push_back(pll(t, res));
    }
    return 0;
}
