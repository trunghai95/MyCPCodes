#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX1 = 300000;
const int MAX2 = 19;
int pow2[MAX2+2];
ll dp[MAX1+2][MAX2+2], sum[MAX1+2];

void init() {
    pow2[0] = 1;
    for (int i = 1; i <= MAX2; ++i) {
        pow2[i] = pow2[i-1] * 2;
    }

    dp[0][0] = 1;
    for (int i = 0; i <= MAX1; ++i) {
        for (int j = 1; j <= MAX2; ++j) {
            for (int k = 0; k <= 9; ++k) {
                int tmp = i + pow2[j-1] * k;
                if (tmp > MAX1) break;
                dp[tmp][j] += dp[i][j-1];
            }
        }
    }

    sum[0] = dp[0][MAX2];
    for (int i = 1; i <= MAX1; ++i)
        sum[i] = sum[i-1] + dp[i][MAX2];
}

int test;
ll n;
char s[50];

void solve(ll n) {
    if (n <= 1) {
        printf("0\n");
        return;
    }

    int lo = 0, hi = MAX1;

    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (sum[mid] < n) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    n -= sum[lo-1];
    for (int i = MAX2; i > 0; --i) {
        ll tmp = 0;
        for (int j = 0; j <= 9; ++j) {
            int k = lo - j*pow2[i-1];
            if (k < 0) break;
            tmp += dp[k][i-1];
            if (tmp >= n) {
                tmp -= dp[k][i-1];
                n -= tmp;
                s[MAX2-i] = '0' + j;
                lo = k;
                break;
            }
        }
    }

    char *res = s;
    while (res[0] == '0') ++res;
    printf("%s\n", res);
}

int main() {
    init();

    scanf("%d", &test);

    while (test --> 0) {
        scanf("%lld", &n);
        solve(n);
    }
    return 0;
}
