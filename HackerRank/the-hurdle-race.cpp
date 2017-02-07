#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int n, k, a, mx;

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        mx = max(mx, a);
    }

    int res = max(0, mx - k);

    printf("%d\n", res);
    return 0;
}
