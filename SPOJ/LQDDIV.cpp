#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int m, n[2];
ll a[40], dif[2][70000], sum[2];

int main() {
    scanf("%d", &m);

    n[0] = m/2;
    n[1] = m - n[0];

    for (int i = 0; i < m; ++i) {
        scanf("%lld", a+i);
        sum[i >= n[0]] += a[i];
    }

    for (int mask = 0; mask < (1 << n[0]); ++mask) {
        ll ss = 0;
        for (int i = 0; i < n[0]; ++i)
        if ((mask >> i) & 1)
            ss += a[i];
        dif[0][mask] = (ss*2 - sum[0]);
    }

    for (int mask = 0; mask < (1 << n[1]); ++mask) {
        ll ss = 0;
        for (int i = 0; i < n[1]; ++i)
        if ((mask >> i) & 1)
            ss += a[i+n[0]];
        dif[1][mask] = (ss*2 - sum[1]);
    }

    sort(dif[1], dif[1] + (1 << n[1]));

    ll res1 = 2e18;
    ll res2 = 0;
    n[0] = (1 << n[0]);
    n[1] = (1 << n[1]);

    for (int i = 0; i < n[0]; ++i) {
        int p = lower_bound(dif[1], dif[1] + n[1], dif[0][i]) - dif[1];
        if (p < n[1]) {
            ll tmp = abs(dif[0][i] - dif[1][p]);
            if (tmp <= res1) {
                int p2 = lower_bound(dif[1], dif[1] + n[1], dif[1][p] + 1) - dif[1];
                if (tmp < res1) {
                    res1 = tmp;
                    res2 = p2 - p;
                } else {
                    res2 += p2 - p;
                }
            }
        }
        if (p > 0) {
            ll tmp = abs(dif[0][i] - dif[1][p-1]);
            if (tmp <= res1) {
                int p2 = lower_bound(dif[1], dif[1] + n[1], dif[1][p-1]) - dif[1];
                if (tmp < res1) {
                    res1 = tmp;
                    res2 = p - p2;
                } else {
                    res2 += p - p2;
                }
            }
        }
    }

    printf("%lld %d\n", res1, res2/2);
    return 0;
}
