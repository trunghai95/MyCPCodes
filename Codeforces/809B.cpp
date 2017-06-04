#include <bits/stdc++.h>

using namespace std;

int n, k, res1, res2;
char s[5];

bool query(int x, int y) {
    printf("1 %d %d\n", x, y);
    fflush(stdout);
    scanf("%s", s);
    return (s[0] == 'T');
}

int search(int lo, int hi) {
    while (lo < hi) {
        int m1 = lo + (hi - lo) / 3;
        int m2 = hi - (hi - lo) / 3;

        if (query(m1, m2)) {
            hi = (m1 + m2) / 2;
        } else {
            lo = (m1 + m2) / 2 + 1;
        }
    }

    return lo;
}

int main() {
    scanf("%d %d", &n, &k);

    res1 = search(1, n);

    if (res1 == 1) {
        res2 = search(2, n);
    } else if (res1 == n) {
        res2 = search(1, n-1);
    } else {
        res2 = search(res1 + 1, n);
        if (!query(res2, res1)) {
            res2 = search(1, res1 - 1);
        }
    }

    printf("2 %d %d\n", res1, res2);
    return 0;
}
