#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int n, x, a[MAXN+2], v[MAXN+2];

int main() {
    scanf("%d %d", &n, &x);

    for (int i = 0; i < n; ++i) {
        scanf("%d", a+i);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", v+i);
    }

    int res = -1;
    double mn = 1e9;

    for (int i = 0; i < n; ++i) {
        a[i] = abs(a[i] - x);
        int g = __gcd(a[i], v[i]);
        a[i] /= g;
        v[i] /= g;

        double tmp = 1.0 * a[i] / v[i];
        if (tmp < mn) {
            mn = tmp;
            res = i;
        } else if (tmp == mn) {
            res = -1;
        }
    }

    printf("%d\n", res);
    return 0;
}
