#include <bits/stdc++.h>

using namespace std;

int test, n;
double d, k, s;

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%lf %d", &d, &n);

        double t = 0;

        for (int i = 1; i <= n; ++i) {
            scanf("%lf %lf", &k, &s);
            k = d - k;
            t = max(t, k/s);
        }

        double res = d / t;

        printf("Case #%d: %.6lf\n", tt, res);
    }
    return 0;
}
