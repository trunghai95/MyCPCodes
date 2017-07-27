#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e6;
int n, a[MAXN+2], be, af, v[MAXN+2];
ll sum;

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
        if (i < a[i]) {
            ++be;
            sum += a[i] - i;
        } else {
            ++af;
            sum += i - a[i];
        }

        if (a[i] != 1) {
            int tmp = a[i] - i;
            if (tmp <= 0)
                tmp += n;
            ++v[tmp];
        }
    }

    int res = 0;
    ll mnsum = sum;

    for (int i = 1; i < n; ++i) {
        sum += a[n-i+1] * 2 - n - 1;
        sum += af - 1 - be;

        if (sum < mnsum) {
            mnsum = sum;
            res = i;
        }

        af += v[i];
        be -= v[i];
        if (a[n-i+1] != 1) {
            --af;
            ++be;
        }
    }

    printf("%lld %d\n", mnsum, res);
    return 0;
}
