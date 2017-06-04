#include <bits/stdc++.h>

using namespace std;

const int MAXN = 15;
const int MAXM = 100;
int n, m, lef[MAXN+2], rig[MAXN+2], dp[MAXN+2][2];
char s[MAXM+4];

int main() {
    scanf("%d %d", &n, &m);

    for (int i = n; i >= 1; --i) {
        scanf("%s", s);
        for (int j = 1; j <= m; ++j)
        if (s[j] == '1') {
            if (!lef[i]) {
                lef[i] = j;
            }
            rig[i] = j;
        }
        if (lef[i])
            lef[i] = m + 1 - lef[i];
    }

    while (n > 0 && !lef[n]) --n;

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    if (n == 1) {
        int res = rig[1];
        printf("%d\n", res);
        return 0;
    }

    dp[1][0] = rig[1]*2;
    dp[1][1] = m+1;

    for (int i = 2; i < n; ++i) {
        if (!lef[i]) {
            dp[i][0] = min(dp[i-1][0] + 1, dp[i-1][1] + m + 2);
            dp[i][1] = min(dp[i-1][1] + 1, dp[i-1][0] + m + 2);
        } else {
            dp[i][0] = min(dp[i-1][0] + 1 + rig[i]*2, dp[i-1][1] + m + 2);
            dp[i][1] = min(dp[i-1][1] + 1 + lef[i]*2, dp[i-1][0] + m + 2);
        }
    }

    int res = min(dp[n-1][0] + 1 + rig[n], dp[n-1][1] + 1 + lef[n]);
    printf("%d\n", res);
    return 0;
}
