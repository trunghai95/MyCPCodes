#include <bits/stdc++.h>

using namespace std;

const int MAXN = 8000;
const int MAXK = 1000;
const double EPS = 1e-7;
int k, q;
double p, dp[MAXN+2][MAXK+2];

void init() {
    dp[0][0] = 1;

    for (int i = 1; i <= MAXN; ++i) {
        int bound = min(i, k);
        for (int j = 1; j <= bound; ++j) {
            dp[i][j] = dp[i-1][j] * j / k + dp[i-1][j-1] * (k - j + 1) / k;
        }
    }
}

int main() {
    scanf("%d %d", &k, &q);
    init();

    while (q --> 0) {
        scanf("%lf", &p);
        p = (p - EPS) / 2000;

        int lo = k, hi = MAXN;

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            // cout << mid << ' ' << dp[mid][k] << ' ' << p << '\n';
            if (dp[mid][k] < p) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        printf("%d\n", lo);
    }
    return 0;
}
