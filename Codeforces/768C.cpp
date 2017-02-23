#include <bits/stdc++.h>

using namespace std;

const int MAXX = 1024;
int n, k, x, cnt[MAXX+2], cache[MAXX+2];

int main() {
    scanf("%d %d %d", &n, &k, &x);

    for (int i = 1, a; i <= n; ++i) {
        scanf("%d", &a);
        ++cnt[a];
    }

    while (k --> 0) {
        bool odd = false;
        for (int i = 0; i < MAXX; ++i)
        if (cnt[i]) {
            if (!odd) {
                cache[i^x] += cnt[i] - cnt[i] / 2;
                cache[i] += cnt[i] / 2;
            } else {
                cache[i] += cnt[i] - cnt[i] / 2;
                cache[i^x] += cnt[i] / 2;
            }

            if (cnt[i]&1) {
                odd = !odd;
            }
        }

        memcpy(cnt, cache, sizeof(cnt));
        memset(cache, 0, sizeof(cache));
    }

    int mx, mn;

    for (int i = 0; i < MAXX; ++i) {
        if (cnt[i]) {
            mn = i;
            break;
        }
    }

    for (int i = MAXX - 1; i >= 0; --i) {
        if (cnt[i]) {
            mx = i;
            break;
        }
    }

    printf("%d %d\n", mx, mn);
    return 0;
}
