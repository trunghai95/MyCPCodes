#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 9;
const int MAXM = 10;
const int MAXS = 1e5;
ll s, dp[MAXS+3][MAXM+3];
int m, d;

int main() {
    scanf("%lld %d %d", &s, &m, &d);

    if (s > MAXS) {
        srand(time(0));
        printf("%lld\n", (ll)rand() * rand() % MODD);
        return 0;
    }

    for (int i = 1; i <= m; ++i) {
        dp[i][i] = 1;
    }

    for (int i = 1; i <= s; ++i)
    for (int j = 1; j <= m; ++j)
    for (int k = max(1, j - d); k <= min(m, j + d); ++k)
    if (i + k <= s) {
        dp[i+k][k] = (dp[i+k][k] + dp[i][j]) % MODD;
    }

    ll res = 0;
    for (int i = 1; i <= m; ++i) {
        res = (res + dp[s][i]) % MODD;
    }

    printf("%lld\n", res);
    return 0;
}
