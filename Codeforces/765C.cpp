#include <bits/stdc++.h>

using namespace std;

int k, a, b;

int main() {
    scanf("%d %d %d", &k, &a, &b);

    if ((a < k && b < k) || (a < k && b%k != 0) || (b < k && a%k != 0)) {
        printf("-1\n");
        return 0;
    }

    int res = a/k + b/k;
    printf("%d\n", res);
    return 0;
}
