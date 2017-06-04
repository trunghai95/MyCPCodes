#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;
const int MAXN = 1e5;
int test, n;
ll a[MAXN+2], dp[MAXN+2];

ll modPow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y&1) {
            res = res * x % MODD;
        }

        y >>= 1;
        x = x * x % MODD;
    }

    return res;
}

ll solve() {
    if (n == 1) {
        return a[1];
    }

    dp[1] = a[1] * modPow(2, n-2) % MODD;
    ll res = dp[1];

    for (int i = 2; i < n; ++i) {
        dp[i] = (dp[i-1] * modPow(2, MODD - 2) + modPow(2, n-3)) % MODD;
        dp[i] = dp[i] * a[i] % MODD;
        res = (res + dp[i]) % MODD;
    }

    dp[n] = dp[n-1] * a[n] % MODD;
    dp[n] = (dp[n] + a[n] * modPow(2, n-2)) % MODD;
    res = (res + dp[n]) % MODD;

    return res;
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d", &n);

        for (int i = 1; i <= n; ++i) {
            scanf("%lld", a+i);
        }

        printf("%lld\n", solve());
    }
    return 0;
}
