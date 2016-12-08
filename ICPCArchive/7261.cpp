#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Rect {
    ll u, v, h;
};

const int MAXN = 10000;
int test, n;
ll r, tmp;
Rect a[MAXN+2];

ll calc(ll x) {
    ll lef = 0, rig = 0;
    for (int i = 1; i <= n; ++i) {
        lef += max(0LL, (min(x, a[i].v) - max(0LL, a[i].u))) * a[i].h;
        rig += max(0LL, (min(r, a[i].v) - max(x, a[i].u))) * a[i].h;
    }
    return lef - rig;
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%lld %d", &r, &n);

        for (int i = 1; i <= n; ++i) {
            scanf("%lld %lld %lld %lld", &a[i].u, &tmp, &a[i].v, &a[i].h);
            a[i].v = min(r, a[i].u + a[i].v);
        }

        ll lo = 0, hi = ++r;

        while (lo < hi) {
            ll mid = (lo + hi) / 2;
            if (calc(mid) >= 0) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        tmp = calc(lo) + 1;
        ++lo, hi = r;

        while (lo < hi) {
            ll mid = (lo + hi) / 2;
            if (calc(mid) >= tmp) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        printf("%lld\n", lo - 1);
    }
    return 0;
}
