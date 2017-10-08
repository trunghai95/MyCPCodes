#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300;
int n, m, x, y, w, a[MAXN+2][MAXN+2], res;

int main() {
    scanf("%d %d", &n, &m);

    while (m --> 0) {
        scanf("%d %d %d", &x, &y, &w);

        int bx = min(n, x + w);
        int by = min(n, y + w);
        for (int i = max(x - w + 1, 0); i < bx; ++i)
        for (int j = max(y - w + 1, 0); j < by; ++j) {
            a[i][j] += w - max(abs(i - x), abs(j - y));
        }
    }

    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
        res = max(res, a[i][j]);
    }

    printf("%d\n", res);
    return 0;
}
