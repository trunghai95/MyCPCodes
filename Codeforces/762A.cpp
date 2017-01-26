#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, i;
int k;
vector<ll> v;

int main() {
    scanf("%lld %d", &n, &k);

    for (i = 1; i*i < n; ++i) {
        if (n % i == 0)
            v.push_back(i);
    }

    if (i*i == n) {
        if (k <= (int)v.size()) {
            printf("%lld\n", v[k-1]);
        } else if (k == (int)v.size() + 1) {
            printf("%lld\n", i);
        } else if (k <= (int)v.size()*2 + 1) {
            printf("%lld\n", n / v[v.size()*2 + 1 - k]);
        } else {
            printf("-1\n");
        }
    } else {
        if (k <= (int)v.size()) {
            printf("%lld\n", v[k-1]);
        } else if (k <= (int)v.size()*2) {
            printf("%lld\n", n / v[v.size()*2 - k]);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}
