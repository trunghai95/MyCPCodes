#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
int n, m, a[MAXN+2], b[MAXN+2], aa[MAXN+2], bb[MAXN+2];

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
    }

    for (int i = 2; i <= n; ++i)
        aa[i] = a[i] - a[i-1];
    aa[1] = a[1] + (m - a[n]);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", b+i);
    }

    for (int i = 2; i <= n; ++i)
        bb[i] = b[i] - b[i-1];
    bb[1] = b[1] + (m - b[n]);

    for (int i = 0; i < n; ++i) {
        bool f = true;
        for (int j = 1; j <= n; ++j) {
            int k = j + i;
            if (k > n) k -= n;
            if (aa[j] != bb[k]) {
                f = false;
                break;
            }
        }

        if (f) {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");
    return 0;
}
