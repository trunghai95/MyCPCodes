#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
const int MAXK = 100000;
int n, k, x, y, a, b, r[8];

int main() {
    scanf("%d %d %d %d", &n, &k, &a, &b);

    for (int i = 0; i < 8; i += 2) {
        r[i] = 1;
        r[i+1] = n;
    }

    r[0] = r[2] = 1;
    r[1] = r[3] = n;
    r[4] = max(1 - a + b, 1);
    r[5] = min(n - a + b, n);
    r[6] = max(a + b - n, 1);
    r[7] = min(a + b - 1, n);

    for (int i = 1; i <= k; ++i) {
        scanf("%d %d", &x, &y);
        if (x == a) {
            if (y < b)
                r[0] = max(r[0], y+1);
            else
                r[1] = min(r[1], y-1);
        } else if (y == b) {
            if (x < a)
                r[2] = max(r[2], x+1);
            else
                r[3] = min(r[3], x-1);
        } else if (x - y == a - b) {
            if (y < b)
                r[4] = max(r[4], y+1);
            else
                r[5] = min(r[5], y-1);
        } else if (x + y == a + b) {
            if (y < b)
                r[6] = max(r[6], y+1);
            else
                r[7] = min(r[7], y-1);
        }
    }

    int res = 0;
    for (int i = 0; i < 8; i += 2) {
        res += r[i+1] - r[i];
    }
    printf("%d\n", res);
    return 0;
}
