#include <bits/stdc++.h>

using namespace std;

int a[10010], m, n;
bool ck[10010];

void init() {
    for (int i = 2; i <= 10000; ++i)
    if (!ck[i]) {
        a[++m] = i;
        for (int j = i*i; j <= 10000; j += i) {
            ck[j] = true;
        }
    }

    for (int i = 1; i <= m; ++i) {
        a[i] += a[i-1];
    }
}

int main() {
    init();
    while (scanf("%d", &n)) {
        if (n == 0) return 0;

        int res = 0;

        for (int i = 1; i <= m; ++i) {
            int p = lower_bound(a+i, a+m+1, n + a[i-1]) - a;
            if (p == m+1 || a[p] != n + a[i-1]) {
                continue;
            }
            ++res;
        }
        printf("%d\n", res);
    }
    return 0;
}