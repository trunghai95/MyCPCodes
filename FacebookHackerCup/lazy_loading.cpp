#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int test, n, a[MAXN+2];

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", a+i);
        sort(a+1, a+1+n);

        int sum = 0, res = 0;
        for (int i = n; i; --i) {
            sum += 49/a[i] + 1;
            if (sum > n) break;
            ++res;
        }
        printf("Case #%d: %d\n", tt, res);
    }
    return 0;
}
