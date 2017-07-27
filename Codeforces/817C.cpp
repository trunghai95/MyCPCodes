#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, s;

ll calc(ll x) {
    ll res = x;

    while (x) {
        res -= x%10;
        x /= 10;
    }

    return res;
}

int main() {
    scanf("%lld %lld", &n, &s);

    ll lo = 1, hi = n+1;

    while (lo < hi) {
        ll mid = (lo + hi) / 2;

        if (calc(mid) >= s) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    printf("%lld\n", n + 1 - lo);
    return 0;
}
