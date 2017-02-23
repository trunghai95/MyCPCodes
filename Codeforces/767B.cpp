#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5;
int n;
ll t1, t2, t, a, r1, r2;

int main() {
    scanf("%lld %lld %lld %d", &t1, &t2, &t, &n);

    r2 = 2e18;

    for (int i = 1; i <= n && t1 + t <= t2; ++i) {
        scanf("%lld", &a);

        if (a > t1) {
            break;
        }

        ll tmp = t1 - (a - 1);
        if (tmp < r2) {
            r2 = tmp;
            r1 = a - 1;
        }

        t1 += t;
    }

    if (t1 + t <= t2) r1 = t1, r2 = 0;

    printf("%lld\n", r1);
    return 0;
}
