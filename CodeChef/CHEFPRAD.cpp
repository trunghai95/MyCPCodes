#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 250;
int test, n, m;
ll a[MAXN+2], b[MAXN+2], e;

void inc(ll x) {
    for (int i = 1; i <= n; ++i) {
        a[i] += x;
    }
}

ll Try() {
    ll res = 0;
    int i = 1, j = 1;

    while (i <= n) {
        while (j <= m && b[j] < a[i] - e) ++j;
        if (j > m) break;
        if (b[j] <= a[i] + e) {
            ++res;
            ++j;
        }
        ++i;
    }

    return res;
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d %d %lld", &n, &m, &e);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", a+i);
        }
        for (int i = 1; i <= m; ++i) {
            scanf("%lld", b+i);
        }
        sort(a+1, a+1+n);
        sort(b+1, b+1+m);

        ll res = Try();

        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            inc(b[j] - a[i]);
            res = max(res, Try());
            inc(a[i] - b[j]);

            inc(b[j] + e - a[i]);
            res = max(res, Try());
            inc(a[i] - b[j] - e);

            inc(b[j] - e - a[i]);
            res = max(res, Try());
            inc(a[i] - b[j] + e);
        }

        printf("%lld\n", res);
    }
    return 0;
}
