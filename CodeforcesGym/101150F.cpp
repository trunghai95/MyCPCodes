#include <bits/stdc++.h>

using namespace std;

int n, a[111];
double b, r, v, e, f, dp[111];

int main() {
    while (true) {
        scanf("%d", &n);
        if (n == 0) return 0;

        for (int i = 1; i <= n; ++i) {
            scanf("%d", a+i);
        }
        scanf("%lf %lf %lf %lf %lf", &b, &r, &v, &e, &f);

        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; ++i) {
            for (int x = 0; x < a[i]; ++x) {
                if (x >= r) {
                    dp[i] += 1.0 / (v - e*(x - r));
                } else {
                    dp[i] += 1.0 / (v - f*(r - x));
                }
            }

            for (int j = 1; j < i; ++j) {
                double tmp = dp[j] + b;
                for (int x = a[j]; x < a[i]; ++x) {
                    if (x-a[j] >= r) {
                        tmp += 1.0 / (v - e*(x - a[j] - r));
                    } else {
                        tmp += 1.0 / (v - f*(r - x + a[j]));
                    }
                }
                dp[i] = min(dp[i], tmp);
            }
        }

        printf("%.4lf\n", dp[n]);
    }
    return 0;
}