#include <bits/stdc++.h>

using namespace std;

int n, m, a[111], res, l, r;

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i)
        scanf("%d", a+i);

    for (int i = 1; i <= m; ++i) {
        scanf("%d %d", &l, &r);
        int sum = 0;
        for (int j = l; j <= r; ++j)
            sum += a[j];
        if (sum > 0) res += sum;
    }

    printf("%d\n", res);
    return 0;
}
