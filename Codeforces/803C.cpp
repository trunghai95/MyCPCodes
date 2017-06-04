#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAXN = 1e6;
ll n, k, sum, g;

int main() {
    scanf("%lld %lld", &k, &n);

    if (n == 1) {
        printf("%lld\n", k);
        return 0;
    }

    sum = n*(n+1)/2;

    if (n > MAXN || sum > k) {
        printf("-1\n");
        return 0;
    }

    g = -1;
    for (ll i = 1; i * i <= k; ++i) {
        if (k % i == 0) {
            if (i <= k/sum) g = max(g, i);
            if ((k/i) <= k/sum) g = max(g, k/i);
        }
    }

    if (g == -1) {
        printf("-1\n");
        return 0;
    }

    for (ll i = 1; i < n; ++i) {
        printf("%lld ", i*g);
    }

    n = k - n*(n-1)/2 * g;
    printf("%lld\n", n);
    return 0;
}
