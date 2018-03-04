#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;

int n, a[MAXN+2];
bool dp[MAXN+2][2];

int main() {
    dp[0][0] = true;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
        if (a[i]&1) {
            for (int j = i; j > 0; --j)
            if ((a[j]&1) && ((i-j+1)&1)) {
                if (dp[j-1][0]) {
                    dp[i][1] = true;
                }
                if (dp[j-1][1]) {
                    dp[i][0] = true;
                }
            }
        }
    }

    if (dp[n][1]) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    return 0;
}