#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int test, n;
double x[MAXN+2], y[MAXN+2], w[MAXN+2];

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d", &n);

        for (int i = 1; i <= n; ++i) {
            scanf("%lf %lf %lf", x+i, y+i, w+i);
        }

        double res = 1e15;
        for (int cx = 1; cx <= n; ++cx)
        for (int cy = 1; cy <= n; ++cy) {
            double sum = 0;
            for (int i = 1; i <= n; ++i) {
                sum += max(abs(x[i] - x[cx]), abs(y[i] - y[cy]));
            }
            cout << x[cx] << ' ' << y[cy] << ' ' << sum << '\n';
            res = min(res, sum);
        }

        printf("Case #%d: %.4lf\n", tt, res);
    }
    return 0;
}
