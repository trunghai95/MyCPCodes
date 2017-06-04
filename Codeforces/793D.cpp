#include <bits/stdc++.h>

using namespace std;

const int MAXN = 80;
int n, k, m, d[MAXN+2][MAXN+2], dp[MAXN+2][MAXN+2][MAXN+2][MAXN+2];

int getMin(int x, int y) {
    if (x < 0) return y;
    if (y < 0) return x;
    return min(x, y);
}

int main() {
    scanf("%d %d %d", &n, &k, &m);
    memset(d, -1, sizeof(d));

    if (k > n) {
        printf("-1\n");
        return 0;
    }

    for (int i = 0, u, v, w; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        d[u][v] = getMin(d[u][v], w);
    }

    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= n; ++i) {
        dp[i][0][n+1][1] = 0;
    }

    int res = -1;

    for (int c = 1; c <= k; ++c)
    for (int i = 1; i <= n; ++i)
    for (int lo = 0; lo < i; ++lo)
    for (int hi = i + 1; hi <= n+1; ++hi)
    if (dp[i][lo][hi][c] != -1) {
        if (c == k) {
            res = getMin(res, dp[i][lo][hi][c]);
            continue;
        }

        if (i - lo - 1 >= k - c) {
            for (int j = lo + 1; j < i; ++j)
            if (d[i][j] != -1) {
                dp[j][lo][i][c+1] = getMin(dp[j][lo][i][c+1], dp[i][lo][hi][c] + d[i][j]);
            }
        }

        if (hi - i - 1 >= k - c) {
            for (int j = i + 1; j < hi; ++j)
            if (d[i][j] != -1) {
                dp[j][i][hi][c+1] = getMin(dp[j][i][hi][c+1], dp[i][lo][hi][c] + d[i][j]);
            }
        }
    }

    printf("%d\n", res);
    return 0;
}
