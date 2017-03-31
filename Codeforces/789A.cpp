#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, k, w[MAXN+2], res;

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", w+i);
        res += (w[i] - 1) / k + 1;
    }

    res = (res - 1) / 2 + 1;
    printf("%d\n", res);
    return 0;
}
