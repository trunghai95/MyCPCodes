#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
char a[MAXN+5], b[MAXN+5];
int dp[2][MAXN+5], n, m;

int main() {
    scanf("%s %s", a+1, b+1);
    n = strlen(a+1);
    m = strlen(b+1);

    for (int i = 1; i <= n; ++i) {
        if (a[i] == b[dp[0][i-1] + 1]) {
            dp[0][i] = dp[0][i-1] + 1;
        } else {
            dp[0][i] = dp[0][i-1];
        }
    }

    for (int i = n; i >= 1; --i) {
        if (a[i] == b[m - dp[1][i+1]]) {
            dp[1][i] = dp[1][i+1] + 1;
        } else {
            dp[1][i] = dp[1][i+1];
        }
    }

    int best = 0, mx = 0;
    for (int i = 0; i <= n; ++i) {
        if (dp[0][i] + dp[1][i+1] > mx) {
            best = i;
            mx = dp[0][i] + dp[1][i+1];
        }
    }

    if (mx == 0) {
        printf("-\n");
    } else if (mx >= m) {
        printf("%s\n", b+1);
    } else {
        for (int i = 1; i <= dp[0][best]; ++i)
            printf("%c", b[i]);
        for (int i = dp[1][best+1]; i >= 1; --i)
            printf("%c", b[m - i + 1]);
        printf("\n");
    }
    return 0;
}
