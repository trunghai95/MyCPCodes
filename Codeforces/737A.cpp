#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAXN = 200000;
const ll INF = 2e9 + 1;
ll n, m, s, t, c[MAXN+5], v[MAXN+5], x[MAXN+5];

ll calc(ll v) {
    ll res = 0, last = 0;

    for (int i = 0; i < m; ++i) {
        ll dist = x[i] - last;
        if (dist > v) return INF;
        if (dist*2 <= v) {
            res += x[i] - last;
        } else {
            ll tmp = v - dist;
            res += tmp + (dist - tmp)*2;
        }
        last = x[i];
    }
    return res;
}

ll search() {
    ll lef = 0, rig = INF;

    while (lef < rig) {
        ll mid = (lef + rig) / 2;
        if (calc(mid) <= t) {
            rig = mid;
        } else {
            lef = mid + 1;
        }
    }

    return lef;
}

int main() {
    scanf("%lld %lld %lld %lld", &n, &m, &s, &t);

    for (int i = 0; i < n; ++i)
        scanf("%lld %lld", c+i, v+i);
    for (int i = 0; i < m; ++i)
        scanf("%lld", x+i);
    x[m++] = s;
    sort(x, x+m);

    ll mn = search();
    ll res = -1;
    for (int i = 0; i < n; ++i)
    if (v[i] >= mn) {
        if (res == -1 || c[i] < res)
            res = c[i];
    }

    printf("%lld\n", res);
    return 0;
}
