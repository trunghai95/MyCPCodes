#include <bits/stdc++.h>

const int MAXN = 1000005;

int n, m, k, tmp;
int cnt[MAXN];

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        cnt[tmp]++;
    }

    int res = 0;

    for (int i = 1; i <= m; i++) {
        int x = cnt[i];
        if (x == 0) {
            continue;
        }
        while (x > 1) {
            // printf("%d %d\n", x, res);
            tmp = x / k;
            if (x % k > 1) {
                tmp++;
            }
            // printf("%d\n", tmp);
            res += tmp;
            if (x % k == 1) {
                tmp++;
            }
            // printf("%d\n", tmp);
            x = tmp;
        }
    }
    printf("%d\n", res);
    return 0;
}