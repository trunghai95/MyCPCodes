#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, m, k, x, y, a[MAXN+2];

int calc(int x, int y) {
    if (y == 0) {
        return x;
    } else if (x == n) {
        return y + n;
    } else if (y == n) {
        return n*3 - x;
    } else {
        return n*4 - y;
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        a[i] = calc(x, y);
    }

    sort(a, a+m);

    int res = 1e9;
    for (int i = 0; i < m; ++i) {
        int j = (i + k - 1) % m;
        if (j < i) {
            res = min(res, n*4 - (a[i] - a[j]));
        } else {
            res = min(res, a[j] - a[i]);
        }
    }

    printf("%d\n", res);
    return 0;
}
