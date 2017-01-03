#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
int n, m, a[MAXN+2], b, res;

int main() {
    scanf("%d", &n);

    memset(a, -1, sizeof(a));
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
        if (a[i] == a[i-1])
            --i, --n;
    }

    reverse(a+1, a+1+n);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &b);
        int pos = lower_bound(a+1, a+1+n, b) - a;
        if (pos > n) {
            res = 0;
        } else {
            res = n - pos;
            if (a[pos] > b)
                ++res;
        }

        printf("%d\n", res+1);
    }
    return 0;
}
