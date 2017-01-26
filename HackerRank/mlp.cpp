#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
    scanf("%d %d", &n, &k);

    if (k > n) {
        printf("-1\n");
        return 0;
    }

    if (n == 1 && k == 1) {
        printf("0\n");
        return 0;
    }

    if (k == 2 && n > 2) {
        printf("-1\n");
        return 0;
    }

    int res = k - 1 + (n - k) * 2;
    printf("%d\n", res);
    return 0;
}
