#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 120;
const ll INF = 1e9 + 7;
int n;
ll cnt[6][2], a[MAXN+2][6], p1, p2;

ll calc(ll x, ll y, ll t) {
    if (t == -1) return 0;
    ll res = 0;
    if (x*2 > y) {
        res = 500;
    } else if (x*4 > y) {
        res = 1000;
    } else if (x*8 > y) {
        res = 1500;
    } else if (x*16 > y) {
        res = 2000;
    } else if (x*32 > y) {
        res = 2500;
    } else {
        res = 3000;
    }

    res = res / 250 * (250 - t);
    return res;
}

bool check(ll x) {
    p1 = p2 = 0;
    for (int j = 1; j <= 5; ++j) {
        if (a[1][j] != -1 && (a[2][j] != -1 && a[1][j] >= a[2][j])) {
            p1 += calc(cnt[j][0] + x, cnt[j][1] + x, a[1][j]);
            p2 += calc(cnt[j][0] + x, cnt[j][1] + x, a[2][j]);
        } else {
            p1 += calc(cnt[j][0], cnt[j][1] + x, a[1][j]);
            p2 += calc(cnt[j][0], cnt[j][1] + x, a[2][j]);
        }
    }
    return p1 > p2;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= 5; ++j) {
        scanf("%lld", a[i]+j);
        ++cnt[j][1];
        if (a[i][j] != -1) {
            ++cnt[j][0];
        }
    }

    for (int i = 0; i <= 10000; ++i) {
        if (check(i)) {
            printf("%d\n", i);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}
