#include <bits/stdc++.h>

using namespace std;

int test, n, s, a[20];

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d %d", &n, &s);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a+i);
        }

        int nn = (1 << n);
        int res = 0;
        for (int mask = 1; mask < nn; ++mask) {
            bool f = true;
            int sum = 0, cnt = 0;
            for (int i = 0; i < n; ++i)
            if ((mask >> i) & 1) {
                sum += a[i];
                ++cnt;
            }

            if (sum < s) continue;

            for (int i = 0; i < n; ++i)
            if (((mask >> i) & 1) && sum - a[i] >= s) {
                f = false;
                break;
            }
            if (f) res = max(res, cnt);
        }
        printf("%d\n", res);
    }
    return 0;
}