#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);
const double EPS = 1e-8;
double d, v;

int main() {

    while (true) {
        scanf("%lf %lf", &d, &v);
        if (d == 0 && v == 0) return 0;

        double lo = 0, hi = d;
        v = d*d*d*PI/4 - v;

        while (hi - lo > EPS) {
            double mid = (lo + hi) / 2;
            double r1 = d/2;
            double r2 = mid/2;
            double h = (d - mid) / 2;
            double sum = mid*mid*mid*PI/4 + PI*h*(r1*r1 + r2*r2 + r1*r2)/3.0*2.0;
            if (sum > v) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        printf("%.3lf\n", lo);
    }
    return 0;
}
