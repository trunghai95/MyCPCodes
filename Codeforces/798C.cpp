#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
int n, a[MAXN+2], g, res;

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
        g = __gcd(g, a[i]);
        a[i] = a[i] & 1;
    }

    if (g > 1) {
        printf("YES\n0\n");
        return 0;
    }

    for (int i = 1; i <= n; ++i)
    if (a[i]) {
        int tmp = i;
        while (i <= n && a[i]) ++i;
        tmp = i - tmp;
        res += tmp / 2;
        if (tmp & 1) {
            res += 2;
        }
    }

    printf("YES\n%d\n", res);
    return 0;
}
