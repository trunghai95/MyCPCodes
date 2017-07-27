#include <bits/stdc++.h>

using namespace std;

struct Info {
    int l, r, cost;
};

bool cmp(Info x, Info y) {
    return x.l < y.l;
}

const int MAXN = 2e5;
const int INF = 2e9 + 1;
int n, x, res;
map<int,int> bit[MAXN+2];
Info a[MAXN+2];

int get(int len, int x) {
    if (len <= 0) return INF;
    int res = INF;
    while (x) {
        if (bit[len].count(x)) {
            res = min(res, bit[len][x]);
        }
        x -= x&(-x);
    }
    return res;
}

void update(int len, int x, int val) {
    while (x <= MAXN) {
        int &t = bit[len][x];
        if (t == 0) {
            t = val;
        } else {
            t = min(t, val);
        }
        x += x&(-x);
    }
}

int main() {
    scanf("%d %d", &n, &x);

    res = INF;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &a[i].l, &a[i].r, &a[i].cost);
    }

    sort(a+1, a+1+n, cmp);

    for (int i = 1; i <= n; ++i) {
        int len = a[i].r - a[i].l + 1;
        int tmp = get(x - len, a[i].l - 1);

        // cout << a[i].l << ' ' << a[i].r << ' ' << a[i].cost << ' ' << tmp << '\n';

        if (tmp != INF) {
            res = min(res, tmp + a[i].cost);
        }

        update(len, a[i].r, a[i].cost);
    }

    if (res == INF) res = -1;
    printf("%d\n", res);
    return 0;
}
