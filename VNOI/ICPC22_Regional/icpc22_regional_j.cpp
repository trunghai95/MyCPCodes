#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MAXN = 150003;
char s[MAXN];
ll dp[MAXN][4];
int n;

int main() {
    while (true) {
        scanf("%s", s);
        if (s[0] == '$') {
            return 0;
        }
        memset(dp, 0, sizeof(dp));
        n = strlen(s);
        if (n < 7) {
            printf("0\n");
            continue;
        }
        if (s[0] == 'I') {
            dp[0][0] = dp[1][0] = 1;
        }
        if (s[1] == 'I') {
            dp[1][0] += 1;
        }
        for (int i = 2; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                dp[i][j] = dp[i-1][j];
            }
            if (s[i] == 'I') {
                dp[i][0]++;
            } else if (s[i] == 'C') {
                dp[i][1] += dp[i-2][0];
                dp[i][3] += dp[i-2][2];
            } else if (s[i] == 'P') {
                dp[i][2] += dp[i-2][1];
            }
        }

        // for (int i = 0; i < n; i++) {
        //     printf("%d-%c: ", i, s[i]);
        //     for (int j = 0; j < 4; j++) {
        //         printf("%lld ", dp[i][j]);
        //     }
        //     printf("\n");
        // }
        printf("%lld\n", dp[n-1][3]);
    }
    return 0;
}