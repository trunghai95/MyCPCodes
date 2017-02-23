#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5;
int test, n, m;
ll a[MAXN+2], b[MAXN+2], x;

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d %d %lld", &n, &m, &x);

        for (int i = 1; i <= n; ++i) {
            scanf("%lld", a+i);
            a[i] += a[i-1];
        }

        for (int i = 1; i <= m; ++i) {
            scanf("%lld", b+i);
            b[i] += b[i-1];
        }

        int res = 0;

        for (int i = 0; i <= n && a[i] <= x; ++i) {
            int j = lower_bound(b+1, b+1+m, x - a[i] + 1) - b - 1;
            res = max(res, i + j);
        }

        printf("%d\n", res);
    }
    return 0;
}
