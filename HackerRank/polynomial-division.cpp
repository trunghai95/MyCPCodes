#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5;
const ll MODD = 1e9 + 7;
int n, q, type, u, v;
ll a[MAXN+2], c1, c2, x, it[MAXN*4 + 2];

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

void build(int node, int lef, int rig) {
    if (lef == rig) {
        it[node] = a[lef];
        return;
    }

    int lnode = (node << 1);
    int rnode = ((node << 1) | 1);
    int mid = ((lef + rig) >> 1);
    build(lnode, lef, mid);
    build(rnode, mid+1, rig);
    int len = mid - lef + 1;
    it[node] = (it[lnode] + it[rnode] * modPow(x, len)) % MODD;
}

void update(int node, int lef, int rig, int pos, ll val) {
    if (lef > pos || rig < pos) {
        return;
    }

    if (lef == rig) {
        it[node] = a[pos] = val;
        return;
    }

    int lnode = (node << 1);
    int rnode = ((node << 1) | 1);
    int mid = ((lef + rig) >> 1);
    update(lnode, lef, mid, pos, val);
    update(rnode, mid+1, rig, pos, val);
    int len = mid - lef + 1;
    it[node] = (it[lnode] + it[rnode] * modPow(x, len)) % MODD;
}

ll get(int node, int lef, int rig, int l, int r) {
    if (lef > r || rig < l) {
        return 0;
    }

    if (lef >= l && rig <= r) {
        return it[node] * modPow(x, lef - l) % MODD;
    }

    int lnode = (node << 1);
    int rnode = ((node << 1) | 1);
    int mid = ((lef + rig) >> 1);
    return (get(lnode, lef, mid, l, r) + get(rnode, mid+1, rig, l, r)) % MODD;
}

int main() {
    scanf("%d %lld %lld %d", &n, &c1, &c2, &q);
    for (int i = 0; i < n; ++i)
        scanf("%lld", a+i);

    x = (MODD - c2) * modPow(c1, MODD - 2) % MODD;
    build(1, 0, n-1);

    while (q --> 0) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d %lld", &u, &c1);
            update(1, 0, n-1, u, c1);
        } else {
            scanf("%d %d", &u, &v);
            ll tmp = get(1, 0, n-1, u, v);
            if (get(1, 0, n-1, u, v) == 0) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}
