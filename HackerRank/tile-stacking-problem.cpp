#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;
const int MAXN = 1e4;
const int MAXM = 1e3;
int n, m, k;
ll dp[MAXN+2][MAXM+2];
int cnt;

ll solve(int n, int m) {
    ++cnt;
    if (m < 1) {
        return 0;
    }
    if (dp[n][m] != -1) return dp[n][m];
    if (n == 0) return (dp[n][m] = 1);
    if (m == 1) {
        if (n > k) return (dp[n][m] = 0);
        else return (dp[n][m] = 1);
    }

    int bound = min(k, n);
    dp[n][m] = 0;
    for (int i = 0; i <= bound; ++i) {
        dp[n][m] = (dp[n][m] + solve(n-i, m-1)) % MODD;
    }

    return dp[n][m];
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", solve(n, m));
    cout << cnt << '\n';
    return 0;
}
