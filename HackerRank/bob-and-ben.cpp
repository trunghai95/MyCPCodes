#include <bits/stdc++.h>

using namespace std;

int test, n, m, k;

int grundy(int m) {
    if (m == 0) return 0;
    if (m == 1) return 1;
    if (m == 2) return 0;
    return (2 - (m&1));
}

int main() {
    scanf("%d", &test);
    while (test --> 0) {
        scanf("%d", &n);
        int res = 0;
        while (n --> 0) {
            scanf("%d %d", &m, &k);
            res ^= grundy(m);
        }
        printf(res?"BOB\n":"BEN\n");
    }
    return 0;
}
