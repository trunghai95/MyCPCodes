#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
int n, a[MAXN+2], lo[MAXN+2], hi[MAXN+2], mx[MAXN+2][MAXN+2], dp[MAXN+2];
bool ck[MAXN+2];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
        if (lo[a[i]] == 0) {
            lo[a[i]] = hi[a[i]] = i;
        } else {
            lo[a[i]] = min(lo[a[i]], i);
            hi[a[i]] = max(hi[a[i]], i);
        }
    }

    for (int j = 1; j <= n; ++j) {
        memset(ck, 0, sizeof(ck));
        int sumxor = a[j], lef = lo[a[j]], rig = hi[a[j]];
        ck[a[j]] = true;

        for (int i = j; i >= 1; --i) {
            if (!ck[a[i]]) {
                ck[a[i]] = true;
                sumxor ^= a[i];
                lef = min(lef, lo[a[i]]);
                rig = max(rig, hi[a[i]]);
            }

            if (rig > j) break;

            if (lef == i) {
                mx[i][j] = sumxor;
            }
        }
    }

    for (int j = 1; j <= n; ++j) {
        for (int i = j; i >= 1; --i) {
            dp[j] = max(dp[j], mx[i][j] + dp[i-1]);
        }
    }

    printf("%d\n", dp[n]);
    return 0;
}
