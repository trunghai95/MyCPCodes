#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second

const int MAXN = 50;
int test, n, cnt;
ll R;
pll a[MAXN+2], b[2];
double r;

bool inRect(int i, int j) {
    ll d1 = a[i].F - b[j].F;
    ll d2 = a[i].S - b[j].S;
    return (d1 >= 0 && d1 <= R && d2 >= 0 && d2 <= R);
}

bool inCir(int i, int j) {
    double cx = 1.0*b[j].F + 1.0*R/2;
    double cy = 1.0*b[j].S + 1.0*R/2;
    double dist = (1.0*a[i].F-cx)*(1.0*a[i].F-cx) + (1.0*a[i].S-cy)*(1.0*a[i].S-cy);
    return (dist <= r);
}

int main() {
    // clock_t t = clock();
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d %lld", &n, &R);
        r = 1.0*R*R/2;
        for (int i = 0; i < n; ++i)
            scanf("%lld %lld", &a[i].F, &a[i].S);

        int res = 0;
        for (int i1 = 0; i1 < n; ++i1)
        for (int j1 = 0; j1 < n; ++j1) {
            b[0] = pll(a[i1].F, a[j1].S);
            for (int i2 = 0; i2 < n; ++i2)
            for (int j2 = 0; j2 < n; ++j2) {
                b[1] = pll(a[i2].F, a[j2].S);
                cnt = 0;
                for (int i = 0; i < n; ++i) {
                    if (inRect(i, 0)) {
                        ++cnt;
                    }

                    if (inRect(i, 1) && !inCir(i, 0)) {
                        ++cnt;
                    }
                }

                res = max(res, cnt);
            }
        }

        printf("Case #%d: %d\n", tt, res);
    }

    // cerr << clock() - t << '\n';
    return 0;
}
