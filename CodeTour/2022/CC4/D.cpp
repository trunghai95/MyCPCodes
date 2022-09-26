#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
int n, a[MAXN], q, x, res;

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        res = res^a[i];
    }

    if (n % 2 == 0) {
        printf("%d\n", res);
        return 0;
    }

    for (int i = 0; i < q; i++) {
        scanf("%d", &x);
        res = res^x;
    }
    printf("%d\n", res);

    return 0;
}