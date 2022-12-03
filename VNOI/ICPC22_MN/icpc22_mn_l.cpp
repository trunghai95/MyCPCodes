#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1004;
int n, res, dp[MAXN][2], tmp, carry;
char a[MAXN], b[MAXN], c[MAXN];

int add(char a, char b) {
    return a - '0' + b - '0';
}

int solve() {
    res = 0;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        tmp = add(a[i], b[i]);
        if (tmp % 10 == c[i] - '0') {
            dp[i][0] = 1;
            carry = tmp / 10;
            for (int j = 1; j < i; j++) {
                dp[i][0] = max(dp[i][0], dp[j][carry] + 1);
            }
            if (dp[i][0] == 1 && tmp >= 10) {
                dp[i][0] = 0;
            }
            res = max(res, dp[i][0]);
        } else if ((tmp + 1) % 10 == c[i] - '0') {
            dp[i][1] = 1;
            carry = (tmp + 1) / 10;
            for (int j = 1; j < i; j++) {
                dp[i][1] = max(dp[i][1], dp[j][carry] + 1);
            }
            if (dp[i][1] == 1 && tmp >= 9) {
                dp[i][1] = 0;
            }
        }
    }
    return n - res;
}

int main() {
    while (true) {
        scanf("%d", &n);
        if (n == 0) {
            return 0;
        }
        scanf("%s %s %s", a+1, b+1, c+1);
        printf("%d\n", solve());
    }
    return 0;
}