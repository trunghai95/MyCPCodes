#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000;
int test, n, a[MAXN+5], lis[MAXN+5], lds[MAXN+5];

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d", &n);

        for (int i = 1; i <= n; ++i)
            scanf("%d", a+i);
        reverse(a+1, a+1+n);
        int res = 0;
        memset(lis, 0, sizeof(lis));
        memset(lds, 0, sizeof(lds));

        for (int i = 1; i <= n; ++i) {
            lis[i] = lds[i] = 1;
            for (int j = 1; j < i; ++j) {
                if (a[j] > a[i]) {
                    lds[i] = max(lds[i], lds[j] + 1);
                } else {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
            res = max(res, lis[i] + lds[i] - 1);
        }


        printf("%d\n", res);
    }
    return 0;
}
