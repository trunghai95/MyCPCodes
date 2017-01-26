#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int n, a[MAXN+2], mx, res;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a+i), mx = max(mx, a[i]);
    for (int i = 1; i <= n; ++i)
        res += mx - a[i];
    printf("%d\n", res);
    return 0;
}
