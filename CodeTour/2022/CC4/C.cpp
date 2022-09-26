#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
int n, m, k, a[MAXN][MAXN], q, x, y, preSum[MAXN][MAXN];

int calcSum(int i, int j1, int j2) {
    if (j1 == 0) {
        return preSum[i][j2];
    }
    return preSum[i][j2] - preSum[i][j1-1];
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            if (j == 0) {
                preSum[i][j] = a[i][j];
            } else {
                preSum[i][j] = preSum[i][j-1] + a[i][j];
            }
        }
    }

    scanf("%d", &q);
    while (q --> 0) {
        scanf("%d %d", &x, &y);
        x--;
        y--;
        int res = 0;
        for (int i = max(0, x-k); i <= min(n-1, x+k); i++) {
            int ydiff = k - abs(x - i);
            res += calcSum(i, max(0, y-ydiff), min(m-1, y+ydiff));
        }
        printf("%d\n", res);
    }
    return 0;
}