#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int n, a[MAXN+5];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d", a+i);

    sort(a+1, a+1+n);

    int res = 1, i = 1, j = 1;

    while (i <= n) {
        while (j <= n && a[j] - a[i] <= 1) ++j;
        res = max(res, j - i);
        ++i;
    }

    printf("%d\n", res);
    return 0;
}
