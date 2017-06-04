// small test
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int test, n, c, m, cnt[3][MAXN+2], sum[3];

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d %d %d", &n, &c, &m);
        memset(cnt, 0, sizeof(cnt));
        sum[1] = sum[2] = 0;

        for (int i = 0, u, v; i < m; ++i) {
            scanf("%d %d", &u, &v);
            ++cnt[v][u];
            ++sum[v];
        }

        int res1 = max(sum[1], sum[2]);
        res1 += max(cnt[1][1] + cnt[2][1] - res1, 0);
        int res2 = 0;

        for (int i = 2; i <= n; ++i) {
            res2 += max(cnt[1][i] + cnt[2][i] - res1, 0);
        }

        printf("Case #%d: %d %d\n", tt, res1, res2);
    }
    return 0;
}
