#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define ll long long

const int MAXN = 2e5+5;
int n, k, test;
ll a[MAXN], dp[2][MAXN], sum;

void solve() {
    memset(dp, 0, sizeof(dp));
    sum = 0;

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < k; i++) {
        sum += a[i];
    }
    dp[0][k-1] = max(0LL, sum);
    dp[1][k-1] = max(0LL, -sum);
    for (int i = k; i < n; i++) {
        int j = i - k;
        sum = sum + a[i] - a[j];
        dp[0][i] = max(dp[0][i-1], dp[1][j] + sum);
        dp[1][i] = max(dp[1][i-1], dp[0][j] - sum);
    }
    printf("%lld\n", max(dp[0][n-1], dp[1][n-1]));
}

int main() {
    scanf("%d\n", &test);
    while (test --> 0) {
        solve();
    }
    return 0;
}