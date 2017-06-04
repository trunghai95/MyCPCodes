#include <bits/stdc++.h>

using namespace std;

int test, n, p, a, cnt[5];

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d %d", &n, &p);
        memset(cnt, 0, sizeof(cnt));

        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a);
            ++cnt[a%p];
        }

        int res = cnt[0];
        if ((cnt[1] + cnt[2]*2 + cnt[3]*3) % p != 0) {
            ++res;
        }

        if (p == 3) {
            int tmp = min(cnt[1], cnt[2]);
            res += tmp;
            cnt[1] -= tmp;
            cnt[2] -= tmp;
            res += cnt[1]/3 + cnt[2]/3;
        } else if (p == 2) {
            res += cnt[1]/2;
        } else {
            res += cnt[2]/2;
            cnt[2] %= 2;
            int tmp = min(cnt[1], cnt[3]);
            res += tmp;
            cnt[1] -= tmp;
            cnt[3] -= tmp;
            cnt[1] = max(cnt[1], cnt[3]);

            tmp = min(cnt[2], cnt[1]/2);
            res += tmp;
            cnt[1] -= tmp*2;
            res += cnt[1]/4;
        }

        printf("Case #%d: %d\n", tt, res);
    }
    return 0;
}
