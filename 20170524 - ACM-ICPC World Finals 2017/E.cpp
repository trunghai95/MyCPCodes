#include <bits/stdc++.h>

using namespace std;

const double INF = 1e12;
const double EPS = 1e-9;
const int MAXN = 1000;
int n;
double t, d[MAXN+2], s[MAXN+2];

double calc(double c) {
    double sum = 0;
    for (int i = 1; i <= n && sum <= t; ++i) {
        sum += d[i] / (s[i] + c);
    }
    return sum;
}

int main() {
    scanf("%d %lf", &n, &t);
    double lo = -INF, hi = INF;

    for (int i = 1; i <= n; ++i) {
        scanf("%lf %lf", d+i, s+i);
        lo = max(lo, EPS - s[i]);
    }

    while (hi - lo > EPS) {
        double mid = (lo + hi) / 2;
        if (calc(mid) < t) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    printf("%.9lf\n", lo);
    return 0;
}
