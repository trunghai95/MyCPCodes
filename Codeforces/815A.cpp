#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int n, m, a[MAXN+2][MAXN+2], cnt[2][MAXN+2], u;

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
        scanf("%d", a[i] + j);
        if (!u && !a[i][j]) u = i;
    }

    if (!u) {
        int mn = a[1][1];
        if (n > m) {
            for (int i = 2; i <= n; ++i)
                mn = min(mn, a[i][1]);
            for (int i = 1; i <= n; ++i)
            if (mn == a[i][1]) {
                u = i;
                break;
            }
        } else {
            for (int i = 2; i <= m; ++i)
                mn = min(mn, a[1][i]);
            cnt[0][1] = mn;
            u = 1;
        }
    }

    for (int i = 1; i <= m; ++i) {
        cnt[1][i] = a[u][i] - cnt[0][u];
    }

    for (int i = 1; i <= n; ++i) {
        cnt[0][i] = a[i][1] - cnt[1][1];
    }

    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
    if (cnt[0][i] < 0 || cnt[1][j] < 0 || cnt[0][i] + cnt[1][j] != a[i][j]) {
        printf("-1\n");
        return 0;
    }

    int sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += cnt[0][i];
    for (int i = 1; i <= m; ++i)
        sum += cnt[1][i];

    printf("%d\n", sum);
    for (int i = 1; i <= n; ++i) {
        while (cnt[0][i] --> 0) {
            printf("row %d\n", i);
        }
    }

    for (int i = 1; i <= m; ++i) {
        while (cnt[1][i] --> 0) {
            printf("col %d\n", i);
        }
    }

    return 0;
}
