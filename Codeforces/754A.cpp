#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int n, a[MAXN+2];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
        a[i] += a[i-1];
    }

    if (a[n] != 0) {
        printf("YES\n1\n1 %d\n", n);
    } else {
        for (int i = 1; i <= n; ++i)
        if (a[i] != 0) {
            printf("YES\n2\n1 %d\n%d %d\n", i, i+1, n);
            return 0;
        }
        printf("NO\n");
    }
    return 0;
}
