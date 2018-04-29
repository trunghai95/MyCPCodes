#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
const double EPS = 1e-8;
int test, n;
double d, k[MAXN+2], s[MAXN+2];

bool Try(double mid) {
    for (int i = 1; i <= n; ++i) {
        if (mid <= s[i]) {
            continue;
        }
        double t = k[i] / (mid - s[i]);

        if (t*mid + EPS < d) {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%lf %d", &d, &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%lf %lf", k+i, s+i);
        }

        double lo = 0, hi = 1e18;
        while (lo + EPS < hi) {
            cout << "";
            double mid = (lo + hi) / 2.0;
            if (Try(mid)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        printf("Case #%d: %.6f\n", tt, lo);
    }
    return 0;
}