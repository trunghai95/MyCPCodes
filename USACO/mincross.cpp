#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAXN = 100000;
ll n, a[MAXN+2], pos[MAXN+2];
ll bit[MAXN+2], sum, res;

void update(ll x) {
    while (x) {
        ++bit[x];
        x -= x&(-x);
    }
}

ll get(ll x) {
    ll res = 0;
    while (x <= n) {
        res += bit[x];
        x += x&(-x);
    }
    return res;
}

int main() {
    freopen("mincross.in", "r", stdin);
    freopen("mincross.out", "w", stdout);
    scanf("%lld", &n);

    for (ll i = 1, x; i <= n; ++i) {
        scanf("%lld", &x);
        pos[x] = i;
    }

    for (ll i = 1; i <= n; ++i) {
        scanf("%lld", a+i);
        a[i] = pos[a[i]];
        update(a[i]);
        sum += get(a[i] + 1);
    }

    res = sum;

    for (ll i = n; i >= 1; --i) {
        sum -= (n - a[i]);
        sum += (a[i] - 1);
        res = min(res, sum);
    }

    printf("%lld\n", res);

    return 0;
}
