#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5;
const ll BOUND = 1e15;
int n;
ll a[MAXN+2], k, res, kk;

ll solve(ll kk) {
    map<ll, ll> mp;
    mp[0] = 1;
    ll ret = 0;

    for (int i = 1; i <= n; ++i) {
        ret += mp[a[i] - kk];
        ++mp[a[i]];
    }

    return ret;
}

int main() {
    scanf("%d %lld", &n, &k);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a+i);
        a[i] += a[i-1];
    }

    kk = 1;

    if (k == 1) {
        res = solve(k);
    } else if (k == -1) {
        res = solve(1) + solve(-1);
    } else {
        while (abs(kk) <= BOUND) {
            // cout << kk << ' ';
            res += solve(kk);
            kk *= k;
        }
    }

    printf("%lld\n", res);

    return 0;
}
