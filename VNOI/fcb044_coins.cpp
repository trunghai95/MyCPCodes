#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll m, k, a, b;

int main() {
    scanf("%lld %lld %lld %lld", &m, &k, &a, &b);

    ll res = 1e18;
    for (ll x = 0; x <= m; x++) {
        ll y = m - x;
        res = min(res, abs(a + x*k - (b + y*k)));
    }
    printf("%lld\n", res);
    return 0;
}