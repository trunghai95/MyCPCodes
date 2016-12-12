#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

const int MAXN = 100;
const int MAXB = 500;
int n, bud, dp[MAXB+5], x, y;

int main() {
    while (true) {
        scanf("%d %d", &bud, &n);
        if (bud == 0 && n == 0) return 0;

        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &x, &y);
            for (int j = bud; j >= x; --j) {
                dp[j] = max(dp[j], dp[j-x] + y);
            }
        }

        int res = -1, res2 = -1;
        for (int i = 0; i <= bud; ++i) {
            if (dp[i] > res) {
                res = dp[i];
                res2 = i;
            }
        }
        printf("%d %d\n", res2, res);
    }
    return 0;
}
