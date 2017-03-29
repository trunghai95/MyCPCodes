#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 500;
const ll INF = 1e15;
int n;
ll a[MAXN+2], res, bound;

ll calc(ll p) {
    ll res = 0;

    for (int i = 1; i <= n; ++i) {
        if (a[i] % p > a[i] / p) {
            return INF;
        }
        res += a[i] / (p + 1);
        if (a[i] % (p+1)) {
            ++res;
        }
    }

    return res;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a+i);
    }

    res = INF;

    if (n == 1) {
        printf("1\n");
        return 0;
    }

    bound = 31623;

    vector<ll> v;

    for (ll i = 1; i <= bound; ++i) {
        v.push_back(i);
    }

    for (ll i = 1; i <= bound; ++i) {
        ll tmp = a[1] / i;

        if (tmp > 0) {
            v.push_back(tmp);
        }

        if (tmp > 1) {
            v.push_back(tmp - 1);
        }
    }

    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; --i) {
        res = calc(v[i]);
        if (res != INF) {
            printf("%lld\n", res);
            return 0;
        }
    }

    return 0;
}
