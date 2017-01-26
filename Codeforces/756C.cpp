#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
int n, it[MAXN*4 + 2], lazy[MAXN*4 + 2], x, type, a[MAXN + 2], res;

void update(int node, int lef, int rig, int l, int r, int val) {
    int lnode = node*2;
    int rnode = node*2 + 1;

    if (lazy[node]) {
        it[node] += lazy[node];
        if (lef < rig) {
            lazy[lnode] += lazy[node];
            lazy[rnode] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (lef > r || rig < l) {
        return;
    }

    if (lef >= l && rig <= r) {
        it[node] += val;
        if (lef < rig) {
            lazy[lnode] += val;
            lazy[rnode] += val;
        }
        return;
    }

    int mid = (lef + rig) / 2;
    update(lnode, lef, mid, l, r, val);
    update(rnode, mid+1, rig, l, r, val);
    it[node] = max(it[lnode], it[rnode]);
}

int get(int node, int lef, int rig) {
    int lnode = node*2;
    int rnode = node*2 + 1;

    if (lazy[node]) {
        it[node] += lazy[node];
        if (lef < rig) {
            lazy[lnode] += lazy[node];
            lazy[rnode] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (it[node] <= 0) {
        return -1;
    }

    if (lef == rig) {
        return lef;
    }

    int mid = (lef + rig) / 2;
    if (it[lnode] + lazy[lnode] > 0) {
        return get(lnode, lef, mid);
    } else {
        return get(rnode, mid+1, rig);
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &type);
        x = n - x;

        if (type == 0) {
            update(1, 0, n-1, x, n-1, -1);
        } else {
            update(1, 0, n-1, x, n-1, 1);
            scanf("%d", a+x);
        }

        res = get(1, 0, n-1);
        if (res != -1) {
            printf("%d\n", a[res]);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}
