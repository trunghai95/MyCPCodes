#include <bits/stdc++.h>

using namespace std;

int test, K;
double x[3], y[3], ang[3], angEdge[3], resx, resy;
const double PI = acos(-1);
const double EPS = 1e-10;

void calAngle(int u, int a, int b) {
    double ang1 = atan((y[a] - y[u]) / (x[a] - x[u]));
    if (x[a] - x[u] < 0)
        ang1 += PI;

    double ang2 = atan((y[b] - y[u]) / (x[b] - x[u]));
    if (x[b] - x[u] < 0)
        ang2 += PI;

    ang[u] = ang2 - ang1;
    if (ang[u] > PI*2)
        ang[u] -= PI*2;
    else if (ang[u] < 0)
        ang[u] += PI*2;

    angEdge[u] = ang1;
}

double solve(double mid) {
    double a[2], b[2], c[2];
    double angAP = angEdge[0] + mid;
    double angCP = angEdge[2] + mid;
    if (angAP > PI*2)
        angAP -= PI*2;
    if (angCP > PI*2)
        angCP -= PI*2;

    a[0] = - tan(angAP);
    b[0] = 1;
    a[1] = - tan(angCP);
    b[1] = 1;

    c[0] = - (a[0] * x[0] + b[0] * y[0]);
    c[1] = - (a[1] * x[2] + b[1] * y[2]);

    resy = (c[1]*a[0] - c[0]*a[1]) / (b[0] * a[1] - b[1] * a[0]);
    if (abs(a[0]) > EPS)
        resx = - (c[0] + b[0] * resy) / a[0];
    else
        resx = - (c[1] + b[1] * resy) / a[1];

    double tmp = atan((resy - y[1]) / (resx - x[1]));
    if (resx - x[1] < 0)
        tmp += PI;
    tmp = tmp - angEdge[1];

    if (tmp < 0)
        tmp += PI*2;
    else if (tmp > PI*2)
        tmp -= PI*2;

    return tmp;
}

int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d", &K);

        for (int i = 0; i < 3; ++i)
            scanf("%lf %lf", x+i, y+i);

        for (int i = 0; i < 3; ++i)
            calAngle(i, (i+1) % 3, (i+2) % 3);

        double lo = 0.0, hi = min(ang[0], min(ang[1], ang[2]));

        while (hi - lo > EPS) {
            double mid = (lo + hi) / 2;
            // cout << mid << ' ' << solve(mid) << '\n';
            if (solve(mid) < mid)
                hi = mid;
            else
                lo = mid;
        }

        solve(lo);
        printf("%d %.5lf %.5lf\n", K, resx, resy);
    }
    return 0;
}
