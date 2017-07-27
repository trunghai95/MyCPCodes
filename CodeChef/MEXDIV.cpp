#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 5e5;
const ll MODD = 1e9 + 7;
int n, k, a[MAXN+2], cnt[MAXN+2];
ll dp[MAXN+2];
set<int> all;

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
    }

    for (int i = 0; i <= n; ++i) {
        all.insert(i);
    }

    int lo = 1, hi = 0;
    int mex = 0;
    ll sum = 1;
    dp[0] = 1;

    while (++hi <= n) {
        if (a[hi] <= n) {
            ++cnt[a[hi]];
        }

        if (a[hi] == mex) {
            all.erase(mex);
            mex = *all.begin();
        }

        while (mex > k) {
            if (a[lo] <= n && --cnt[a[lo]] == 0) {
                all.insert(a[lo]);
                if (a[lo] < mex) mex = a[lo];
            }
            sum = (sum - dp[lo-1] + MODD) % MODD;
            ++lo;
        }

        dp[hi] = sum;
        sum = (sum + dp[hi]) % MODD;
    }

    printf("%lld\n", dp[n]);
    return 0;
}
