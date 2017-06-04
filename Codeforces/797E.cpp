#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, a[MAXN+2], q, p, k;

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
    }

    scanf("%d", &q);

    while (q --> 0) {
        scanf("%d %d", &p, &k);

        int cnt = 0;

        while (p <= n) {
            ++cnt;
            p = p + a[p] + k;
        }

        printf("%d\n", cnt);
    }
    return 0;
}
