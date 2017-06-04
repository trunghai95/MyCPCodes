#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int n, k, a[MAXN+2][MAXN+2];

int main() {
    scanf("%d %d", &n, &k);

    if (k > n*n) {
        printf("-1\n");
        return 0;
    }

    for (int i = 1; i <= n && k; ++i)
    for (int j = i; j <= n && k; ++j) {
        if (i == j) {
            --k;
            a[i][j] = 1;
        } else if (k > 1) {
            k -= 2;
            a[i][j] = a[j][i] = 1;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
