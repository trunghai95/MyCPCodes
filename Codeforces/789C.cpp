#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5;
int n;
ll a[MAXN+2], mx[MAXN+2], mn[MAXN+2];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a+i);
    }

    --n;
    for (int i = 1; i <= n; ++i) {
        a[i] = abs(a[i] - a[i+1]);
    }

    mx[n] = mn[n] = a[n];

    for (int i = n-1; i > 0; --i) {
        if (mx[i+1] < 0) {
            mn[i] = a[i];
        } else {
            mn[i] = a[i] - mx[i+1];
        }

        if (mn[i+1] > 0) {
            mx[i] = a[i];
        } else {
            mx[i] = a[i] - mn[i+1];
        }
    }

    ll res = -1e18;
    for (int i = 1; i <= n; ++i) {
        res = max(res, mx[i]);
    }

    printf("%lld\n", res);
    return 0;
}
