#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 60;
const ll INF = 2e18;
const ll MAXX = 1e18;
int n;
ll b, dp[MAXN+2];
char s[MAXN+2];

int main() {
    scanf("%lld %s", &b, s+1);
    n = strlen(s+1);

    fill(dp, dp+1+n, INF);

    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        if (dp[i-1] >= INF/b)
            continue;

        ll cur = 0;
        ll tmp = dp[i-1] * b;

        if (s[i] == '0') {
            if (tmp <= MAXX)
                dp[i] = min(dp[i], tmp);
            continue;
        }

        for (int j = i; j <= n; ++j) {
            cur = cur*10 + s[j] - '0';
            if (cur >= b)
                break;
            ll sum = tmp + cur;
            if (sum > MAXX)
                continue;
            dp[j] = min(dp[j], sum);
        }
    }


    printf("%lld\n", dp[n]);
    return 0;
}
