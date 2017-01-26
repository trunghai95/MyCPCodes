#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e18;
int test;
ll n, m, k;

ll solve(ll n, ll m, ll k) {
    if (k*2 + 3 > m) return INF;
    return 1LL + (n-1)/k;
}

int main() {

    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%lld %lld %lld", &n, &m, &k);
        printf("Case #%d: ", tt);

        if (k >= n || k >= m) {
            printf("-1\n");
            continue;
        }

        ll res = min(solve(n, m, k), solve(m, n, k));

        if (res == INF) res = -1;
        if (k == 1 && res > 5) res = 5;
        if (k >= 2 && res > 4) res = 4;

        printf("%lld\n", res);
    }
    return 0;
}
