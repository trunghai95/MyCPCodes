#include <bits/stdc++.h>

using namespace std;

const int MAX = 1440;
const int MAX2 = 720;
int test, n, m, a[MAX+2], u, v;
int dp[MAX+2][MAX2+2][2];

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d %d", &n, &m);
        memset(a, -1, sizeof(a));

        while (n --> 0) {
            scanf("%d %d", &u, &v);
            for (int i = u+1; i <= v; ++i) {
                a[i] = 0;
            }
        }

        while (m --> 0) {
            scanf("%d %d", &u, &v);
            for (int i = u+1; i <= v; ++i) {
                a[i] = 1;
            }
        }

        memset(dp, -1, sizeof(dp));
        dp[0][0][0] = dp[0][0][1] = 0;

        for (int i = 1; i <= MAX; ++i) {
            int bound = min(i, MAX2);
            
            if (a[i] != 0) {
                for (int j = 1; j <= bound; ++j) {
                    if (dp[i-1][i-j][1] == -1) {
                        dp[i][j][0] = dp[i-1][j-1][0];
                    } else if (dp[i-1][j-1][0] == -1) {
                        dp[i][j][0] = dp[i-1][i-j][1] + 1;
                    } else {
                        dp[i][j][0] = min(dp[i-1][j-1][0], dp[i-1][i-j][1] + 1);
                    }
                }
            }

            if (a[i] != 1) {
                for (int j = 1; j <= bound; ++j) {
                    if (dp[i-1][i-j][0] == -1) {
                        dp[i][j][1] = dp[i-1][j-1][1];
                    } else if (dp[i-1][j-1][1] == -1) {
                        dp[i][j][1] = dp[i-1][i-j][0] + 1;
                    } else {
                        dp[i][j][1] = min(dp[i-1][j-1][1], dp[i-1][i-j][0] + 1);
                    }
                }
            }
        }

        int res = 0;
        if (dp[MAX][MAX2][0] == -1) {
            res = dp[MAX][MAX2][1];
        } else if (dp[MAX][MAX2][1] == -1) {
            res = dp[MAX][MAX2][0];
        } else {
            res = min(dp[MAX][MAX2][0], dp[MAX][MAX2][1]);
        }

        if (res & 1) ++res;
        printf("Case #%d: %d\n", tt, res);
    }
    return 0;
}
