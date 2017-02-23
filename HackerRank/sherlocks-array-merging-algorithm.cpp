#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1200;
const ll MODD = 1e9 + 7;
int n, a[MAXN+2];
ll dp[MAXN+2][MAXN+2], fact[MAXN+2], ifact[MAXN+2];

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

void init() {
    fact[0] = ifact[0] = 1;
    for (int i = 1; i <= MAXN; ++i) {
        fact[i] = fact[i-1] * i % MODD;
        ifact[i] = modPow(fact[i], MODD - 2);
    }
}

int main() {
    init();
    scanf("%d", &n);

    a[0] = 1e9;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (j > 1 && a[i-j+1] > a[i-j+2]) {
                break;
            }

            if (j == i) {
                dp[i][j] = 1;
            } else {
                for (int k = j; k <= i - j; ++k) {
                    dp[i][j] = (dp[i][j] + 
                        (dp[i-j][k] * fact[k] % MODD) * ifact[k-j] % MODD) % MODD;
                }
            }
        }
    }

    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        res = (res + dp[n][i]) % MODD;
    }

    printf("%lld\n", res);

    return 0;
}
