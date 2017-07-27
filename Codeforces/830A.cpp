#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
const int MAXM = 2000;
int n, m, p, a[MAXN+2], b[MAXM+2], dp[MAXN+2][MAXM+2];

int main() {
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d", b+i);
    }

    sort(a+1, a+1+n);
    sort(b+1, b+1+m);

    for (int i = 1; i <= n; ++i)
    for (int j = i; j <= m; ++j) {
        dp[i][j] = max(dp[i-1][j-1], abs(a[i]-b[j]) + abs(b[j]-p));
        if (j > i) dp[i][j] = min(dp[i][j], dp[i][j-1]);
    }

    printf("%d\n", dp[n][m]);
    return 0;
}
