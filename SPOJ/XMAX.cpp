#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100000;
int n;
ll a[MAXN+5];
vector<ll> bucket[65], v;

int len(ll x) {
    int res = 0;
    while (x) {
        ++res;
        x >>= 1;
    }
    return res;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a+i);
        bucket[len(a[i])].push_back(a[i]);
    }

    for (int i = 64; i > 0; --i)
    if (bucket[i].size()) {
        v.push_back(bucket[i][0]);
        for (int j = 1; j < (int)bucket[i].size(); ++j) {
            ll tmp = bucket[i][0] ^ bucket[i][j];
            bucket[len(tmp)].push_back(tmp);
        }
    }

    ll res = 0;
    for (int i = 0; i < (int)v.size(); ++i) {
        if ((res ^ v[i]) > res) {
            res ^= v[i];
        }
    }

    printf("%lld\n", res);

    return 0;
}
