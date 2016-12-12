#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int n, a[MAXN+5], dp[MAXN+5][MAXN+5];

int get(int l, int r) {
    return (a[r] - a[l-1]) % 100;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i)
            scanf("%d", a+i), a[i] = a[i] + a[i-1];

        for (int i = 2; i <= n; ++i) {
            dp[i-1][i] = get(i-1, i-1) * get(i, i);
            for (int j = i-2; j >= 1; --j) {
                dp[j][i] = 2e9;
                for (int k = j; k < i; ++k) {
                    dp[j][i] = min(dp[j][i], dp[j][k] + dp[k+1][i] + get(j,k)*get(k+1,i));
                }
            }
        }

        printf("%d\n", dp[1][n]);
    }

    return 0;
}
