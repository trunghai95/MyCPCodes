#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
struct Ring {
    ll a, b, h;
};

bool cmp(Ring x, Ring y) {
    if (x.b != y.b) {
        return x.b > y.b;
    }

    return x.a > y.a;
}

const int MAXN = 1e5;
const ll INF = 1e15;
int n;
Ring r[MAXN+2];
ll res;
map<ll, ll> bit;

void update(ll x, ll val) {
    while (x <= INF) {
        bit[x] = max(bit[x], val);
        x += x&(-x);
    }
}

ll get(ll x) {
    ll res = 0;
    while (x) {
        res = max(res, bit[x]);
        x -= x&(-x);
    }
    return res;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld %lld %lld", &r[i].a, &r[i].b, &r[i].h);
    }

    sort(r+1, r+1+n, cmp);

    for (int i = 1; i <= n; ++i) {
        ll tmp = get(r[i].b - 1);
        tmp += r[i].h;

        res = max(tmp, res);
        update(r[i].a, tmp);
    }

    printf("%lld\n", res);
    return 0;
}
