#include <bits/stdc++.h>

using namespace std;

int test, n, x[40], y[40], cnt;

bool check(int n, int b) {
    cnt = 0;
    while (n) {
        x[cnt++] = n % b;
        n /= b;
    }

    memcpy(y, x, cnt * sizeof(int));
    reverse(y, y+cnt);
    for (int i = 0; i < cnt; ++i)
    if (x[i] != y[i])
        return false;
    return true;
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d", &n);

        bool f = false;
        for (int i = 2; i <= 16; ++i)
        if (check(n, i)) {
            printf("%d ", i);
            f = true;
        }

        if (!f) printf("-1");
        printf("\n");
    }
    return 0;
}
