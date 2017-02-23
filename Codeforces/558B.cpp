#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
const int MAXX = 1000000;

int n, a[MAXN+2], rl, rr, cnt[MAXX+2], mx, first[MAXX+2], last[MAXX+2];

int main() {
    scanf("%d", &n);

    rl = 1, rr = n;

    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
        mx = max(mx, ++cnt[a[i]]);
        if (first[a[i]] == 0) {
            first[a[i]] = i;
        }
        last[a[i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        int x = a[i];
        if (cnt[x] == mx) {
            if (rr - rl > last[x] - first[x]) {
                rl = first[x];
                rr = last[x];
            }
        }
    }

    printf("%d %d\n", rl, rr);
    return 0;
}
