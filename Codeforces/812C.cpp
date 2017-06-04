#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5;
int n;
ll s, a[MAXN+2], b[MAXN+2];

ll calc(ll k) {
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i] + k*i;
    }

    sort(b+1, b+1+n);
    ll res = 0;
    for (int i = 1; i <= k; ++i) {
        res += b[i];
    }

    return res;
}

int main() {
    scanf("%d %lld", &n, &s);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a+i);
    }

    ll lo = 0, hi = n;

    while (lo < hi) {
        ll mid = (lo + hi) / 2 + 1;

        if (calc(mid) <= s) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    printf("%lld %lld\n", lo, calc(lo));
    return 0;
}
