#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000;
int na, nb, test, dp[MAXN+5][MAXN+5];
char a[MAXN+5], b[MAXN+5];

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%s %s", a+1, b+1);
        na = strlen(a+1);
        nb = strlen(b+1);

        memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= na; ++i)
        for (int j = 0; j <= nb; ++j) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
            }
        }

        printf("%d\n", dp[na][nb]);
    }
    return 0;
}
