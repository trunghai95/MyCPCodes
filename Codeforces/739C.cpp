#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 300000;
int n, m, u, v;
ll a[MAXN + 2], d;
int res[MAXN*4 + 2], pl[MAXN*4 + 2], pr[MAXN*4 + 2];
int nl[MAXN*4 + 2], nr[MAXN*4 + 2], bl[MAXN*4 + 2], br[MAXN*4 + 2];

void ITupdate(int node, int l, int r, int pos, ll val) {
    if (l > r) return;
    if (pos != -1 && (pos < l || pos > r)) return;
    if (l == r) {
        a[l] += val;
        res[node] = (a[l] != 0);
        if (a[l] > 0) {
            pl[node] = pr[node] = bl[node] = br[node] = 1;
            nl[node] = nr[node] = 0;
        } else if (a[l] < 0) {
            nl[node] = nr[node] = bl[node] = br[node] = 1;
            pl[node] = pr[node] = 0;
        } else {
            pl[node] = pr[node] = bl[node] = br[node] = nl[node] = nr[node] = 0;
        }
        return;
    }

    int m = (l + r) / 2, lnode = node*2, rnode = node*2 + 1;;
    ITupdate(lnode, l, m, pos, val);
    ITupdate(rnode, m + 1, r, pos, val);
    res[node] = max(res[lnode], res[rnode]);
    
    if (pl[lnode] == (m-l+1)) {
        pl[node] = pl[lnode] + pl[rnode];
        bl[node] = bl[lnode] + bl[rnode];
        nl[node] = 0;
    } else {
        pl[node] = pl[lnode];
        if (nl[lnode] == (m-l+1)) {
            nl[node] = nl[lnode] + nl[rnode];
            bl[node] = nl[node];
        } else {
            nl[node] = nl[lnode];
            if (bl[lnode] == (m-l+1)) {
                bl[node] = bl[lnode] + nl[rnode];
            } else {
                bl[node] = bl[lnode];
            }
        }
    }

    if (nr[rnode] == (r-m)) {
        nr[node] = nr[rnode] + nr[lnode];
        br[node] = br[rnode] + br[lnode];
        pr[node] = 0;
    } else {
        nr[node] = nr[rnode];
        if (pr[rnode] == (r-m)) {
            pr[node] = pr[rnode] + pr[lnode];
            br[node] = pr[node];
        } else {
            pr[node] = pr[rnode];
            if (br[rnode] == (r-m)) {
                br[node] = br[rnode] + pr[lnode];
            } else {
                br[node] = br[rnode];
            }
        }
    }

    res[node] = max(res[node], pr[lnode] + bl[rnode]);
    res[node] = max(res[node], br[lnode] + nl[rnode]);
    res[node] = max(res[node], bl[node]);
    res[node] = max(res[node], br[node]);
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%lld", a+i);
    --n;
    for (int i = 1; i <= n; ++i)
        a[i] = a[i+1] - a[i];

    ITupdate(1, 1, n, -1, 0);
    scanf("%d", &m);
    while (m --> 0) {
        scanf("%d %d %lld", &u, &v, &d);
        ITupdate(1, 1, n, u-1, d);
        ITupdate(1, 1, n, v, -d);
        printf("%d\n", res[1] + 1);
    }
    return 0;
}
