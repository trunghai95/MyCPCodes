#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
const int MAXS = 200;
const int MAXK = 2000;
int test, n, s, k, dp[MAXN+3][MAXS+3][MAXK+3];

void init() {
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i <= MAXS; ++i)
        dp[1][i][0] = i;

    for (int i = 1; i < MAXN; ++i)
    for (int j = 0; j <= MAXS; ++j)
    for (int k = 0; k <= MAXK; ++k)
    if (dp[i][j][k] != -1) {
        for (int x = 0; x <= dp[i][j][k]; ++x) {
            int kk = k + j - x*i;
            if (j + x > MAXS || kk > MAXK) {
                break;
            }

            dp[i+1][j+x][kk] = max(dp[i+1][j+x][kk], x);
        }
    }
}

int main() {
    init();

    scanf("%d", &test);
    while (test --> 0) {
        scanf("%d %d %d", &n, &s, &k);

        if (dp[n][s][k] == -1) {
            printf("-1\n");
            continue;
        }

        int last = 0;
        for (int i = 1; i < n; ++i) {
            for (int x = last; x <= s; ++x)
            if (k - (s - (n - i + 1) * x) >= 0
                && dp[n-i][s-x][k - (s - (n - i + 1) * x)] >= x) {
                
                printf("%d ", x);
                k -= (s - (n - i + 1) * x);
                s -= x;
                last = x;
                break;
            }
        }

        printf("%d\n", s);
    }
    return 0;
}
