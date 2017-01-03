#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
int cur, n, c, d;
int max2 = -INF, min1 = INF, max1 = -INF;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &c, &d);

        if (d == 1) {
            min1 = min(min1, cur);
            max1 = max(max1, cur);
        } else {
            max2 = max(max2, cur);
        }

        cur += c;
    }

    if (max2 >= min1) {
        printf("Impossible\n");
        return 0;
    }

    if (max2 == -INF) {
        printf("Infinity\n");
        return 0;
    }

    cur += 1899 - max2;
    printf("%d\n", cur);

    return 0;
}
