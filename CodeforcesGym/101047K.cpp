#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000;
int test, n;
double a[MAXN+5], res;

double calc(double a, double b, double c) {
    return (a+b+c)*(a+b-c)*(b+c-a)*(c+a-b);
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lf", a+i);
        }

        sort(a, a+n);
        res = -1;

        for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j) {
            int pl = lower_bound(a+j+1, a+n, a[j]-a[i]+1) - a;
            int pr = lower_bound(a+j+1, a+n, a[i]+a[j]) - a - 1;

            if (pl > pr || pl >= n) continue;

            double tmp = min(calc(a[i], a[j], a[pl]), calc(a[i], a[j], a[pr]));
            if (res < 0 || res > tmp)
                res = tmp;
        }

        if (res < 0) {
            printf("-1\n");
        } else {
            printf("%.12lf\n", sqrt(1.0*res) / 4);
        }
    }
    return 0;
}
