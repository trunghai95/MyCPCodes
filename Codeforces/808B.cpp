#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int n, k;
double a[MAXN+2];

int main() {
    scanf("%d %d", &n, &k);

    double sum = 0, res = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lf", a+i);
        sum += a[i];
        if (i >= k) {
            sum -= a[i-k];
            res += sum;
        }
    }

    res = res / (1.0 * (n - k + 1));
    printf("%.10lf\n", res);
    return 0;
}
