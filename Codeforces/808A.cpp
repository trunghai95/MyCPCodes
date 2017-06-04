#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, res;

int main() {
    res = 1e15;
    cin >> n;

    for (ll i = 1; i <= 9; ++i) {
        ll x = i;

        while (x <= n) {
            x *= 10;
        }

        res = min(res, x - n);
    }

    cout << res << '\n';
    return 0;
}
