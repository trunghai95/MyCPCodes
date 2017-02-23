#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MODD = 1e9 + 7;
ll n, k;

ll f(ll n) {
    if (n == 1)
        return 1;

    ll res = n;

    for (ll i = 2; i * i <= n; ++i)
    if (n % i == 0) {
        res = res / i * (i - 1);
        while (n % i == 0) {
            n /= i;
        }
    }

    if (n > 1) {
        res = res / n * (n - 1);
    }
    
    return res;
}

int main() {
    scanf("%lld %lld", &n, &k);

    ll res = n;

    k = (k + 1) / 2;
    for (int i = 1; i <= k; ++i) {
        if (res == 1) {
            break;
        }

        res = f(res);
    }

    res %= MODD;
    printf("%lld\n", res);
    return 0;
}
