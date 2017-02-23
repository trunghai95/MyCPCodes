#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, l, r;

ll countBit(ll n) {
    ll res = 0;

    while (n) {
        ++res;
        n >>= 1;
    }

    return res;
}

ll solve(ll n, ll p) {
    ll nbit = countBit(n);
    nbit = (1LL << nbit) - 1;
    ll mid = (nbit >> 1) + 1;

    if (p == mid) {
        return (n&1);
    }

    if (p > mid) {
        p = nbit - p + 1;
    }
    return solve(n>>1, p);
}

int main() {
    scanf("%lld %lld %lld", &n, &l, &r);

    ll res = 0;
    for (ll i = l; i <= r; ++i) {
        // cout << n << ' ' << i << ' ' << solve(n, i) << '\n';
        res += solve(n, i);
    }

    printf("%lld\n", res);

    return 0;
}
