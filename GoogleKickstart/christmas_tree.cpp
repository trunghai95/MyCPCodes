#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int test, n, m, k, sum[MAXN+4][MAXN+4];
char s[MAXN+4][MAXN+4];

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d %d %d", &n, &m, &k);
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; ++i) {
            scanf("%s", s[i]+1);
            for (int j = 1; j <= m; ++j) {
                sum[i][j] = sum[i][j-1] + (s[i][j] == '#');
            }
        }

        int res = 0;
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        if (s[i][j] == '#') {
            int cnt = 1;
            for (int ii = i+1; ii <= n; ++ii) {
                int d = ii - i;
                int u = j - d, v = j + d;
                if (u < 1 || v > m) break;
                if (sum[ii][v] - sum[ii][u-1] < d * 2 + 1) break;
                cnt += v - u + 1;
            }
            res = max(res, cnt);
        }

        printf("Case #%d: %d\n", tt, res);
    }
    return 0;
}
