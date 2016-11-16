#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b;

void solveSmall(int n, ll k, int tt) {
    if (n == 1) {
        printf("Case %d: %lld\n", tt, k);
        return;
    }

    if (n == 2) {
        ll lef = 0, rig = 3e9;
        while (lef < rig) {
            ll mid = (lef + rig) / 2 + 1;
            if (mid*(mid+1)/2 > k) {
                rig = mid - 1;
            } else {
                lef = mid;
            }
        }

        k -= lef*(lef+1)/2;
        printf("Case %d: %lld %lld\n", tt, k, lef - k);
    }

    if (n == 3) {
        ll sum = 0, lef = 0;
        for (; lef <= 2000000; ++lef) {
            if (sum + (lef + 1)*(lef + 2) / 2 > k) {
                --lef;
                break;
            }
            sum += (lef + 1)*(lef + 2) / 2;
        }

        cout << lef << '\n';
    }
}

int main() {
    int n;
    ll k;
    cin >> n >> k;
    solveSmall(n, k, 1);
    // cin >> a >> b;
    // set<ll> s;
    // for (ll i = 0; i <= 1000; ++i) {
    //     bool f = false;
    //     for (ll x = 0; !f && x <= 3000; ++x)
    //     for (ll y = 0; !f && y <= 3000; ++y) {
    //         if (a*x + b*y == i) {
    //             f = true;
    //         }
    //     }

    //     if (!f) cout << i << '\n';
    // }
    return 0;
}
