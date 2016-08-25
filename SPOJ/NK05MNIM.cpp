#include <bits/stdc++.h>

using namespace std;

int n, a, res, test, cnt;

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d", &n);

        res = cnt = 0;

        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            res ^= a;
            cnt += a;
        }

        if (cnt == n) {
            res = (res == 0);
        }

        if (res)
            printf("1\n");
        else
            printf("-1\n");
    }
    return 0;
}