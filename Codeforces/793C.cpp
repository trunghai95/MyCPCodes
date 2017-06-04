#include <bits/stdc++.h>

using namespace std;

typedef pair<double,double> pdd;
#define F first
#define S second

const double EPS = 1e-15;
int n;
double ax, ay, bx, by;
double vx, vy, rx, ry;
double lo, hi;

int main() {
    scanf("%d %lf %lf %lf %lf", &n, &ax, &ay, &bx, &by);
    lo = 0, hi = 2e18;

    for (int i = 1; i <= n; ++i) {
        scanf("%lf %lf %lf %lf", &rx, &ry, &vx, &vy);
        double a, b, c, d;

        if (rx > ax && rx < bx) {
            a = 0;
        } else if (vx == 0) {
            a = -1;
        } else {
            a = min((ax - rx) / vx, (bx - rx) / vx) + EPS;
        }
        if (vx == 0) {
            b = 2e18;
        } else {
            b = max((ax - rx) / vx, (bx - rx) / vx) - EPS;
        }

        if (ry > ay && ry < by) {
            c = 0;
        } else if (vy == 0) {
            c = -1;
        } else {
            c = min((ay - ry) / vy, (by - ry) / vy) + EPS;
        }
        if (vy == 0) {
            d = 2e18;
        } else {
            d = max((ay - ry) / vy, (by - ry) / vy) - EPS;
        }

        // cout << i << ' ' << a << ' ' << b << ' ' << c << ' ' << d << '\n';

        if (a < 0 || b < 0 || c < 0 || d < 0 || a > b || c > d || b < c || a > d) {
            printf("-1\n");
            return 0;
        }

        lo = max(lo, max(a, c));
        hi = min(hi, min(b, d));

        if (lo > hi) {
            printf("-1\n");
            return 0;
        }
    }

    printf("%.20lf\n", lo);
    return 0;
}
