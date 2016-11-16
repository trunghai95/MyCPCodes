#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second

const int MAXN = 200000;
ll n, x, s;
int m, k;
pll cache[MAXN+5];
vector<pll> a, b;

int main() {
    scanf("%lld %d %d %lld %lld", &n, &m, &k, &x, &s);
    for (int i = 0; i < m; ++i)
        scanf("%lld", &cache[i].S);
    for (int i = 0; i < m; ++i)
        scanf("%lld", &cache[i].F);
    sort(cache, cache+m);

    for (int i = 0; i < m; ++i) {
        if (cache[i].F > s)
            break;
        if (a.empty()) {
            a.push_back(cache[i]);
        } else if (cache[i].F > a.back().F && cache[i].S < a.back().S) {
            a.push_back(cache[i]);
        }
    }

    for (int i = 0; i < k; ++i)
        scanf("%lld", &cache[i].S);
    for (int i = 0; i < k; ++i)
        scanf("%lld", &cache[i].F);
    sort(cache, cache+k);

    for (int i = 0; i < k; ++i) {
        if (cache[i].F > s)
            break;
        if (b.empty()) {
            b.push_back(cache[i]);
        } else if (cache[i].F == b.back().F) {
            b.back().S = cache[i].S;
        } else if (cache[i].F > b.back().F && cache[i].S > a.back().S) {
            b.push_back(cache[i]);
        }
    }

    if (a.empty()) {
        if (b.empty()) {
            printf("%lld\n", n*x);
        } else {
            printf("%lld\n", max(0LL, n - b.back().S) * x);
        }
        return 0;
    }

    if (b.empty()) {
        printf("%lld\n", a.back().S * n);
        return 0;
    }

    ll res = 2e18;
    for (int i = 0; i < (int)a.size(); ++i) {
        int p = lower_bound(b.begin(), b.end(), pll(s - a[i].F + 1, 0)) - b.begin();
        --p;
        if (p < 0) {
            res = min(res, n*a[i].S);
        } else {
            res = min(res, max(0LL, n - b[p].S) * a[i].S);
        }
    }

    printf("%lld\n", res);
    return 0;
}
