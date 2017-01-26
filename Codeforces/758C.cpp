#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100;

int n, m, x, y;
ll k, cnt[MAXN+2][MAXN+2], mx, mn, sum;

ll count(ll x, ll y) {
    // cout << "\n++ " << x << ' ' << y << '\n';
    if (n == 1) {
        ll res = k / m;
        if (y <= k%m) ++res;
        return res;
    }

    ll res = 0;
    ll kk = k;
    ll turns = kk / sum;
    kk %= sum;
    if (x == 1) {
        res = (turns+1)/2;
    } else if (x == n) {
        res = turns/2;
    } else {
        res = turns;
    }

    // cout << turns << ' ' << res << ' ' << kk << '\n';

    if (kk == 0) return res;

    if (turns&1) {
        int lastx = (kk-1) / m + 1;
        int lasty = (kk - 1) % m + 1;
        lastx = n - lastx + 1;
        // cout << "a " << lastx << ' ' << lasty << '\n';
        if (x > lastx || (x == lastx && y <= lasty)) {
            ++res;
        }
    } else {
        int lastx = (kk-1) / m + 1;
        int lasty = (kk - 1) % m + 1;
        // cout << "b " << lastx << ' ' << lasty << '\n';
        if (x < lastx || (x == lastx && y <= lasty)) {
            ++res;
        }
    }
    return res;
}

int main() {
    scanf("%d %d %lld %d %d", &n, &m, &k, &x, &y);
    sum = (n-1)*m;

    mx = 0, mn = 2e18;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cnt[i][j] = count(i, j);
            // cout << cnt[i][j] << ' ';
            mx = max(mx, cnt[i][j]);
            mn = min(mn, cnt[i][j]);
        }
        // cout << '\n';
    }

    printf("%lld %lld %lld\n", mx, mn, cnt[x][y]);
    return 0;
}
