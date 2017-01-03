#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;
const int MAXN = 100000;
ll fact[MAXN+2], inv[MAXN+2], dp[MAXN+2];

ll myPow(ll x, ll y) {
    ll res = 1;

    while (y) {
        if (y&1) {
            res = res * x % MODD;
        }
        x = x * x % MODD;
        y >>= 1;
    }
    return res;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; ++i) {
        fact[i] = fact[i-1] * i % MODD;
        inv[i] = myPow(i, MODD - 2);
    }

    dp[1] = 1;
    for (int i = 2; i <= MAXN; ++i) {
        dp[i] = dp[i-1] * i % MODD;
        dp[i] = (dp[i] - (dp[i] * inv[i-1] % MODD) + MODD * MODD) % MODD;
        dp[i] = (dp[i] + fact[i]) % MODD;
    }
}

int n;

int main() {
    init();
    scanf("%d", &n);
    printf("%lld\n", dp[n]);
    return 0;
}
