#include <bits/stdc++.h>

using namespace std;

const int MAXN = 40;
const int INF = 2e9;
int test, r, p, n, m, c[MAXN+2], a[MAXN+2];
bool ck[MAXN+2];

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d %d %d %d", &r, &p, &n, &m);

        memset(ck, 0, sizeof(ck));
        for (int i = 0, x; i < m; ++i) {
            scanf("%d", &x);
            ck[x] = true;
        }

        for (int i = 0; i < p; ++i) {
            scanf("%d", c+i);
            if (ck[i]) {
                c[i] = 0;
            }
        }

        for (int i = 0, x; i < r; ++i) {
            a[i] = 0;
            for (int j = 0; j < p; ++j) {
                scanf("%d", &x);
                a[i] |= (x << j);
            }
        }

        int res = INF;

        for (int mask = 0; mask < (1 << p); ++mask) {
            int sum = 0;
            for (int i = 0; i < p; ++i)
            if ((mask >> i) & 1) {
                sum += c[i];
            }

            if (sum >= res) continue;

            int cnt = 0;
            for (int i = 0; i < r; ++i)
            if ((mask & a[i]) == a[i]) {
                ++cnt;
            }

            if (cnt >= n) {
                res = sum;
            }
        }

        printf("%d\n", res);
    }
    return 0;
}
