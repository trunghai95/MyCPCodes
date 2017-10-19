#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589793;
const int MAXN = 1e3;
int test, n;
double w, l, d, v, rb, wb, vb, vv;

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d %lf %lf %lf %lf", &n, &w, &l, &d, &v);

        for (int i = 1; i <= n; ++i) {
            scanf("%lf %lf", &rb, &wb);
            vb = PI*4.0/3.0*rb*rb*rb;
            v += min(vb, vb*wb);
        }

        v /= w;
        v /= l;
        v = min(v, d);

        printf("%.11lf\n", v);
    }
    return 0;
}
