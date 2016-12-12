#include <bits/stdc++.h>

using namespace std;

int n, m, a[111][111], b[111][111];

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
        scanf("%d", b[i]+j);
        a[i][j] = 1;
    }

    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
    if (!b[i][j]) {
        for (int k = 1; k <= n; ++k)
            a[k][j] = 0;
        for (int k = 1; k <= m; ++k)
            a[i][k] = 0;
    }

    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
    if (b[i][j]) {
        int f = 0;
        for (int k = 1; k <= n; ++k)
            f |= a[k][j];
        for (int k = 1; k <= m; ++k)
            f |= a[i][k];

        if (!f) {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}
