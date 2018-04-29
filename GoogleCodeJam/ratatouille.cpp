// trau bo
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
int test, n, m, a[MAXN+2][MAXN+2], b[MAXN+2];

int getMin(int x, int y) {
    int mn = (int)(1.0 * x / 1.1 + 0.5);
    if (mn == 0) return 0;
    return (mn - 1) / y + 1;
}

int getMax(int x, int y) {
    int mx = (int)(1.0 * x / 0.9);
    return mx / y;
}

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d %d", &n, &m);

        for (int i = 1; i <= n; ++i) {
            scanf("%d", b+i);
        }

        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            scanf("%d", a[i]+j);
        }

        sort(a[1] + 1, a[1] + 1 + m);

        int res = 0;
        do {
            int cnt = 0;
            for (int i = 1; i <= m; ++i) {
                int mn = 0, mx = 1e9;
                for (int j = 1; j <= n; ++j) {
                    mn = max(mn, getMin(a[j][i], b[j]));
                    mx = min(mx, getMax(a[j][i], b[j]));
                }
                if (mn <= mx) ++cnt;
            }
            res = max(res, cnt);
        } while (next_permutation(a[1] + 1, a[1] + 1 + m));

        printf("Case #%d: %d\n", tt, res);
    }
    return 0;
}
