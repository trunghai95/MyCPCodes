#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
const int INF = 2e9;
int test, n, m, a, cntr[MAXN+2], cntc[MAXN+2], resr, resc, sum;

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d %d", &m, &n);
        memset(cntr, 0, sizeof(cntr));
        memset(cntc, 0, sizeof(cntc));

        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &a);
            cntr[i] += a;
            cntc[j] += a;
        }

        resr = resc = INF;

        for (int i = 1; i <= n; ++i) {
            sum = 0;
            for (int j = 1; j <= n; ++j) {
                sum += cntr[j] * abs(i - j);
            }
            resr = min(resr, sum);
        }

        for (int i = 1; i <= m; ++i) {
            sum = 0;
            for (int j = 1; j <= m; ++j) {
                sum += cntc[j] * abs(i - j);
            }
            resc = min(resc, sum);
        }

        printf("%d blocks\n", resr + resc);
    }
    return 0;
}
