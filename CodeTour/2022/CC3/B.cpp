#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int MAXN = 200005;
int n, q;
ll a[MAXN], prefixSum[MAXN], sum, offset, x, diff;
char c;

ll calcSum(ll lo, ll hi) {
    if (lo == 0) {
        return prefixSum[hi];
    }
    return prefixSum[hi] - prefixSum[lo-1];
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += abs(a[i]);
    }
    sort(a, a+n);
    prefixSum[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = a[i] + prefixSum[i-1];
    }

    printf("%lld\n", sum);
    while (q --> 0) {
        scanf("\n%c %lld", &c, &x);
        // printf("%c %lld\n", c, x);
        if (c == 'B') {
            int lo = lower_bound(a, a+n, - x - offset) - a;
            int hi = upper_bound(a, a+n, -offset) - a - 1;
            if (lo == n) {
                // All are on negative side
                diff = - x * n;
            } else {
                int cnt = hi - lo + 1;
                diff = x * cnt + (calcSum(lo, hi) + offset * cnt) * 2;
                diff -= x * lo;
                diff += x * (n - 1 - hi);
            }
            // printf("%d %d %lld %lld\n", lo, hi, offset, diff);
            sum += diff;
            offset += x;
        } else {
            int lo = lower_bound(a, a+n, -offset) - a;
            int hi = upper_bound(a, a+n, x - offset) - a - 1;
            if (lo == n) {
                diff = x * n;
            } else {
                int cnt = hi - lo + 1;
                diff = x * cnt - (calcSum(lo, hi) + offset * cnt) * 2;
                diff += x * lo;
                diff -= x * (n - 1 - hi);
            }
            // printf("%d %d %lld %lld\n", lo, hi, offset, diff);
            sum += diff;
            offset -= x;
        }
        printf("%lld\n", sum);
    }

    return 0;
}