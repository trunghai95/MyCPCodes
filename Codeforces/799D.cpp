#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second

const ll MAXN = 34;
const ll INF = 1e9;
ll n, a, b, h, w, x[100005];

int main() {
    scanf("%lld %lld %lld %lld %lld", &a, &b, &h, &w, &n);
    if (a > b) swap(a, b);
    if (h > w) swap(h, w);

    for (ll i = 0; i < n; ++i) {
        scanf("%lld", x+i);
    }

    sort(x, x+n, greater<ll>());
    n = min(n, MAXN);

    map<pll, ll> dist;
    queue<pll> q;
    q.push(pll(h, w));
    dist[pll(h, w)] = 0;

    while (!q.empty()) {
        pll u = q.front(); q.pop();
        ll d = dist[u];
        if (u.F >= a && u.S >= b) {
            printf("%lld\n", d);
            return 0;
        }

        if (d >= n) continue;
        if (u.F < a) {
            pll v(u.F * x[d], u.S);
            if (v.F > v.S) swap(v.F, v.S);
            if (!dist.count(v)) {
                dist[v] = d + 1;
                q.push(v);
            }
        }
        if (u.S < b) {
            pll v(u.F, u.S * x[d]);
            if (!dist.count(v)) {
                dist[v] = d + 1;
                q.push(v);
            }
        }
    }

    printf("-1\n");
    return 0;
}
