#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;

int test, n, nb, nc, a[MAXN+2], b[MAXN+2], c[MAXN+2];

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            if (i&1) {
                scanf("%d", &c[i/2]);
            } else {
                scanf("%d", &b[i/2]);
            }
        }

        nc = n/2;
        nb = n - nc;
        sort(b, b+nb);
        sort(c, c+nc);

        for (int i = 0; i < n; ++i) {
            if (i&1) {
                a[i] = c[i/2];
            } else {
                a[i] = b[i/2];
            }
        }

        int res = -1;
        for (int i = 0; i < n-1; ++i) {
            if (a[i] > a[i+1]) {
                res = i;
                break;
            }
        }

        printf("Case #%d: ", tt);
        if (res == -1) {
            printf("OK\n");
        } else {
            printf("%d\n", res);
        }
    }
    return 0;
}