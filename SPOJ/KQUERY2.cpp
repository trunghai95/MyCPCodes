#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30000;
const int MAX = 10000;
const int BLKSZ = 174;

int n, a[MAXN + 5], bit[MAXN/BLKSZ + 5][MAX + 5];
int q, u, v, k, ublock, vblock, res, type, tmp;

void update(int pos, int x, int val) {
    while (x) {
        bit[pos][x] += val;
        x -= x&(-x);
    }
}

int get(int pos, int x) {
    int ret = 0;
    while (x <= MAX) {
        ret += bit[pos][x];
        x += x&(-x);
    }
    return ret;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", a+i);
        update(i/BLKSZ, a[i], 1);
    }

    scanf("%d", &q);

    while (q --> 0) {
        scanf("%d", &type);

        if (type) {
            scanf("%d %d %d", &u, &v, &k);
            ++k;
            ublock = (--u) / BLKSZ;
            vblock = (--v) / BLKSZ;
            res = 0;

            for (int i = ublock*BLKSZ; i < u; ++i)
            if (a[i] >= k)
                --res;

            tmp = min(n, (vblock+1)*BLKSZ);
            for (int i = v+1; i < tmp; ++i)
            if (a[i] >= k)
                --res;

            for (int i = ublock; i <= vblock; ++i)
                res += get(i, k);

            printf("%d\n", res);
        } else {
            scanf("%d %d", &u, &k);
            --u;
            update(u/BLKSZ, a[u], -1);
            update(u/BLKSZ, k, 1);
            a[u] = k;
        }
    }
    return 0;
}
