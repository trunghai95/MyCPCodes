#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
const int INF = 1e9;
int n, a[MAXN+3];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
        if (a[i] != 0) a[i] = INF;
    }

    for (int i = 2; i <= n; ++i) {
        a[i] = min(a[i], a[i-1] + 1);
    }
    for (int i = n-1; i >= 1; --i) {
        a[i] = min(a[i], a[i+1] + 1);
    }

    for (int i = 1; i <= n; ++i) {
        printf("%d ", a[i]);
    }

    printf("\n");
    return 0;
}
