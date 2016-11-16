#include <bits/stdc++.h>

using namespace std;

int n, C[30][30];
double p, dp[30];

void init() {
    for (int i = 0; i <= 20; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
}

int main() {
    scanf("%d %lf", &n, &p);
    
    init();

    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            dp[i] += dp[j] * pow(1.0 - p, j*(i-j)) * C[i-1][j-1];
        }
        dp[i] = 1.0 - dp[i];
    }
    cout << dp[n] << '\n';
    return 0;
}
