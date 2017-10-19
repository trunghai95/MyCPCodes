#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, q, a[MAXN+2], x;

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
    }

    for (int i = n-1; i >= 1; --i) {
        a[i] = min(a[i], a[i+1]);
    }

    scanf("%d", &q);

    while (q --> 0) {
        scanf("%d", &x);

        if (x < a[1]) {
            printf("-1\n");
            continue;
        }

        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2 + 1;

            if (a[mid] > x) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }

        printf("%d\n", lo);
    }
    return 0;
}
