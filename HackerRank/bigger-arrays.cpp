#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;
const int MAXN = 1e5;
int n, q, type, l, r;
ll a[MAXN+2], it[2][MAXN*4+2], lazy[2][MAXN*4+2], x;

ll modPow(ll x, ll y) {
    ll res = 1;

    while (y) {
        if (y&1) {
            res = res*x % MODD;
        }

        y >>= 1;
        x = x*x % MODD;
    }
    return res;
}

void build(int p, int node, int lef, int rig) {
    lazy[p][node] = -1;

    if (lef == rig) {
        it[p][node] = a[lef] - p;
        return;
    }

    int mid = (lef + rig) / 2;
    int lnode = node*2;
    int rnode = lnode + 1;
    build(p, lnode, lef, mid);
    build(p, rnode, mid + 1, rig);

    it[p][node] = it[p][lnode] * it[p][rnode] % MODD;
}

ll get(int p, int node, int lef, int rig, int l, int r) {
    int lnode = node*2;
    int rnode = lnode + 1;

    if (lazy[p][node] != -1) {
        if (lef < rig) {
            lazy[p][lnode] = lazy[p][rnode] = lazy[p][node];
        }

        it[p][node] = modPow(lazy[p][node], rig - lef + 1);
        lazy[p][node] = -1;
    }

    if (rig < l || lef > r || lef > rig) {
        return 1;
    }

    if (lef >= l && rig <= r) {
        return it[p][node];
    }

    int mid = (lef + rig) / 2;
    return get(p, lnode, lef, mid, l, r) * get(p, rnode, mid+1, rig, l, r) % MODD;
}

void update(int p, int node, int lef, int rig, int l, int r, ll val) {
    int lnode = node*2;
    int rnode = lnode + 1;

    if (lazy[p][node] != -1) {
        if (lef < rig) {
            lazy[p][lnode] = lazy[p][rnode] = lazy[p][node];
        }

        it[p][node] = modPow(lazy[p][node], rig - lef + 1);
        lazy[p][node] = -1;
    }

    if (rig < l || lef > r || lef > rig) {
        return;
    }

    if (lef >= l && rig <= r) {
        if (lef < rig) {
            lazy[p][lnode] = lazy[p][rnode] = val - p;
        }

        it[p][node] = modPow(val - p, rig - lef + 1);
        return;
    }

    int mid = (lef + rig) / 2;
    update(p, lnode, lef, mid, l, r, val);
    update(p, rnode, mid+1, rig, l, r, val);

    it[p][node] = it[p][lnode] * it[p][rnode] % MODD;
}

int main() {
    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; ++i) {
        scanf("%lld", a+i);
    }

    build(0, 1, 0, n-1);
    build(1, 1, 0, n-1);

    while (q --> 0) {
        scanf("%d %d %d", &type, &l, &r);
        --l, --r;

        if (type == 1) {
            scanf("%lld", &x);
            update(0, 1, 0, n-1, l, r, x);
            update(1, 1, 0, n-1, l, r, x);
        } else {
            ll res = (get(0,1,0,n-1,l,r) - get(1,1,0,n-1,l,r) + MODD) % MODD;

            printf("%lld\n", res);
        }
    }
    return 0;
}
