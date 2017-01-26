#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100000;
int n;
ll a[MAXN+2], pre[MAXN+2], suf[MAXN+2];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a+i);
    }

    if (n == 1) {
        for (ll i = 2; i <= 200; ++i)
        if (a[1] % i != 0) {
            printf("%lld\n", i);
            return 0;
        }
        return 0;
    }

    pre[1] = a[1];
    for (int i = 2; i <= n; ++i)
        pre[i] = __gcd(pre[i-1], a[i]);
    suf[n] = a[n];
    for (int i = n-1; i >= 1; --i)
        suf[i] = __gcd(suf[i+1], a[i]);

    for (int i = 1; i <= n; ++i) {
        ll gg;
        if (i == 1) {
            gg = suf[2];
        } else if (i == n) {
            gg = pre[n-1];
        } else {
            gg = __gcd(pre[i-1], suf[i+1]);
        }

        // gg /= __gcd(gg, a[i]);
        if (a[i] % gg != 0) {
            printf("%lld\n", gg);
            return 0;
        }
    }
    return 0;
}
