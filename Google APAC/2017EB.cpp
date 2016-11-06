#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test, tt;
ll n;

ll calc(ll b, ll k) {
    ll bb = 1, sum = 1;
    for (int i = 1; i < k; ++i) {
        if (bb > 1e18/b)
            return 2e18;

        bb = bb*b;
        sum += bb;
    }
    return sum;
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%lld", &n);

        ll res = n-1;

        for (ll k = 2; k <= 60; ++k) {
            ll lef = 2, rig = n-1;

            if (lef > rig) continue;
            
            while (lef < rig) {
                ll mid = (lef + rig) / 2;
                if (calc(mid, k) < n) {
                    lef = mid + 1;
                } else {
                    rig = mid;
                }
            }

            if (calc(lef, k) == n) {
                res = min(res, lef);
            }
        }

        printf("Case #%d: %lld\n", ++tt, res);
    }
    return 0;
}
