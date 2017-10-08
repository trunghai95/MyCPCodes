#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int n, a[MAXN+2];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
    }

    for (int i = 3; i <= n; ++i)
    if (a[i] - a[i-1] != a[i-1] - a[i-2]) {
        printf("%d\n", a[n]);
        return 0;
    }

    printf("%d\n", a[n]*2 - a[n-1]);
    return 0;
}
