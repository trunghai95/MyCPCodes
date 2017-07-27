#include <bits/stdc++.h>

using namespace std;

int n, d;
double a, mn;

int main() {
    scanf("%d %lf", &n, &a);

    mn = 1e9;

    for (int i = 1; i <= n - 2; ++i) {
        double tmp = abs(a - 180.0 / n * i);
        if (tmp < mn) {
            mn = tmp;
            d = i;
        }
    }

    printf("2 1 %d\n", d + 2);
    return 0;
}
