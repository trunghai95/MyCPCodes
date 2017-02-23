#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test;
ll n, m, s, k;

ll solve1() {
    return (m - k) * (s - n + 1) + k;
}

ll solve2() {
    ll x = s / n, y = s % n;
    return (m - k - 1) * (x + y) + s + (n - 1) * (n - 2) / 2 * x;
}

ll solve3() {
    ll x = s / n, y = s % n;
    ll res = (m - k - 1) * (x + (y > 0)) + s + (n - 1) * (n - 2) / 2 * x;
    ll r = n - 2, l = n - y;

    if (l <= r) {
        res += (r - l + 1) * (r + l) / 2;
    }

    return res;
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%lld %lld %lld", &n, &m, &s);
        --n;

        if (n == 1) {
            printf("%lld\n", s);
            continue;
        }

        k = (n - 1) * n / 2;
        if (m <= k) {
            printf("%lld\n", s + (m - n));
            continue;
        }

        printf("%lld\n", min(solve1(), min(solve2(), solve3())));
    }
    return 0;
}
