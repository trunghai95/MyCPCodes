#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2000;
int n, x[2], y[2];
ll diag[2][MAXN*2 + 5], maxSum[2];
ll a[MAXN + 3][MAXN + 3];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
        scanf("%lld", a[i] + j);
        diag[0][i+j] += a[i][j];
        diag[1][i-j+n] += a[i][j];
    }

    maxSum[0] = -1;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
        ll sum = diag[0][i+j] + diag[1][i-j+n] - a[i][j];
        if (sum > maxSum[0]) {
            x[0] = i;
            y[0] = j;
            maxSum[0] = sum;
        }
    }

    maxSum[1] = -1;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
    if (((i - x[0]) ^ (j - y[0])) & 1) {
        ll sum = diag[0][i+j] + diag[1][i-j+n] - a[i][j];
        if (sum > maxSum[1]) {
            x[1] = i;
            y[1] = j;
            maxSum[1] = sum;
        }
    }

    printf("%lld\n", maxSum[0] + maxSum[1]);
    for (int i = 0; i < 2; ++i)
        printf("%d %d ", x[i], y[i]);
    printf("\n");
    return 0;
}
