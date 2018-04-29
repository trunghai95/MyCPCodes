#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
#define F first
#define S second

const int MAXN = 1000;
int test, n, k;
pdd a[MAXN+2];

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d %d", &n, &k);

        for (int i = 1; i <= n; ++i) {
            scanf("%lf %lf", &a[i].F, &a[i].S);
            double t1 = a[i].F * a[i].F * M_PI;
            double t2 = a[i].F * a[i].S * M_PI * 2.0;
            a[i] = pdd(t2, t1);
        }

        sort(a+1, a+1+n, greater<pdd>());
        double sum = 0, mx = 0, res = 0;
        for (int i = 1; i < k; ++i) {
            sum += a[i].F;
            mx = max(mx, a[i].S);
        }

        for (int i = k; i <= n; ++i) {
            double mx2 = max(mx, a[i].S);
            double sum2 = sum + a[i].F;
            res = max(res, mx2 + sum2);
        }

        printf("Case #%d: %.9lf\n", tt, res);
    }
    return 0;
}
