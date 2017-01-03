#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
    scanf("%d %d", &n, &k);
    k = 240 - k;

    for (int i = 1; i <= n; ++i) {
        if (k - i*5 < 0) {
            printf("%d\n", i-1);
            return 0;
        }

        k -= i*5;
    }

    printf("%d\n", n);
    return 0;
}
