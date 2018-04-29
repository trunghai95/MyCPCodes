#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
const double INF = 1e14;
int test, n, q, u, v;
double e[MAXN+2], s[MAXN+2], d[MAXN+2][MAXN+2];

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d %d", &n, &q);

        for (int i = 1; i <= n; ++i) {
            scanf("%lf %lf", e+i, s+i);
        }

        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            scanf("%lf", d[i]+j);
            if (d[i][j] < 0) {
                d[i][j] = INF;
            }
        }

        for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }

        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (d[i][j] <= e[i]) {
                d[i][j] = d[i][j] / s[i];
            } else {
                d[i][j] = INF;
            }
        }

        for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }

        printf("Case #%d: ", tt);
        while (q --> 0) {
            scanf("%d %d", &u, &v);
            printf("%.8lf ", d[u][v]);
        }

        printf("\n");
    }
    return 0;
}
