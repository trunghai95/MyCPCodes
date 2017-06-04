#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5;
ll n, k, a[MAXN+2], mn = 1e9;

int main() {
    scanf("%lld %lld", &n, &k);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a+i);
        mn = min(mn, a[i]);
    }

    if (n == 1) {
        printf("0\n");
        return 0;
    }

    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] % k != mn % k) {
            printf("-1\n");
            return 0;
        }

        res += (a[i] - mn) / k;
    }

    printf("%lld\n", res);
    return 0;
}
