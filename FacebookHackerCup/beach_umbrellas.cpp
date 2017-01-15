#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MODD = 1e9 + 7;

const int MAXN = 2000;
int test, n, m, r[MAXN+2], sum, tmp;
ll res, fact[MAXN+2], factinv[MAXN+2];

ll modPow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y&1) {
            res = res*x % MODD;
        }
        y >>= 1;
        x = x*x % MODD;
    }
    return res;
}

void init() {
    fact[0] = factinv[0] = fact[1] = factinv[1] = 1;
    for (int i = 2; i <= MAXN; ++i) {
        fact[i] = fact[i-1] * i % MODD;
        factinv[i] = modPow(fact[i], MODD-2);
    }
}

ll C(const ll &n, ll k) {
    if (n-k < k) k = n-k;
    ll res = 1;
    for (int i = n-k+1; i <= n; ++i)
        res = res*i % MODD;
    res = res*factinv[k] % MODD;
    return res;
}

int main() {
    // clock_t t = clock();
    init();
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d %d", &n, &m);
        sum = 0; res = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", r+i);
            sum += r[i];
        }

        sum = m+n - ((sum<<1) | 1);
        for (int i = 1; i < n; ++i) {
            for (int j = i+1; j <= n; ++j) {
                tmp = sum + r[i] + r[j];
                if (tmp < n) continue;

                res = (res + ((C(tmp, n) * fact[n-2]) << 1)) % MODD;
            }
        }

        printf("Case #%d: %lld\n", tt, res);
    }

    // cout << clock() - t << '\n';
    return 0;
}
