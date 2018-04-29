#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5;
const ll MODD = 1e9 + 7;
int test, n, cnt[MAXN+3], pre[MAXN+3], suf[MAXN+3];
ll pow2[MAXN+3];

void init() {
    pow2[0] = 1;
    for (int i = 1; i <= MAXN; ++i) {
        pow2[i] = pow2[i-1] * 2LL % MODD;
    }
}

int main() {
    init();
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        memset(pre, 0, sizeof(pre));
        memset(suf, 0, sizeof(suf));

        for (int i = 0, x; i < n; ++i) {
            scanf("%d", &x);
            ++cnt[x];
        }

        for (int i = 1; i <= MAXN; ++i) {
            pre[i] = pre[i-1] + cnt[i];
        }
        for (int i = MAXN; i >= 1; --i) {
            suf[i] = suf[i+1] + cnt[i];
        }

        ll res = 0;

        for (int i = 1; i <= MAXN; ++i) {
            res = (res + (pow2[pre[i-1]] * (pow2[cnt[i]]-1) % MODD) * i) % MODD;
            res = (res - (pow2[suf[i+1]] * (pow2[cnt[i]]-1) % MODD) * i + MODD * MODD) % MODD;
        }

        printf("Case #%d: %lld\n", tt, res);
    }
    return 0;
}
