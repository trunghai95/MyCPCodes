#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
set<ll> v;
ll res = 2e18, x;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &x);
        set<ll>::iterator it = v.lower_bound(x+1);
        if (it != v.end()) {
            res = min(res, *it - x);
        }
        v.insert(x);
    }

    printf("%lld\n", res);
    return 0;
}
