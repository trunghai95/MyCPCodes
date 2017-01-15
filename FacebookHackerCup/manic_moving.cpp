#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100;
const int MAXK = 5000;
const ll INF = 1e15;
int test, n, m, k, u, v, a[MAXK+2], b[MAXK+2];
ll w, dist[MAXN+2][MAXN+2], f[MAXK+2][2];

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i <= n; ++i) {
            fill(dist[i]+1, dist[i]+1+n, INF);
            dist[i][i] = 0;
        }

        for (int i = 0; i < m; ++i) {
            scanf("%d %d %lld", &u, &v, &w);
            dist[u][v] = dist[v][u] = min(dist[u][v], w);
        }

        for (int kk = 1; kk <= n; ++kk)
        for (int i = 1; i < n; ++i)
        for (int j = i+1; j <= n; ++j) {
            dist[i][j] = dist[j][i] = min(dist[i][j], dist[i][kk] + dist[kk][j]);
        }

        bool ok = true;
        for (int i = 1; i <= k; ++i) {
            scanf("%d %d", a+i, b+i);
            if (dist[1][a[i]] >= INF || dist[1][b[i]] >= INF)
                ok = false;
        }

        if (!ok) {
            printf("Case #%d: -1\n", tt);
            continue;
        }

        if (k == 1) {
            printf("Case #%d: %lld\n", tt, dist[1][a[1]] + dist[a[1]][b[1]]);
            continue;
        }

        f[1][0] = dist[1][a[1]];

        for (int i = 2; i <= k; ++i) {
            f[i][0] = f[i-1][0] + dist[a[i-1]][b[i-1]] + dist[b[i-1]][a[i]];
            f[i][1] = f[i-1][0] + dist[a[i-1]][a[i]];

            if (i > 2) {
                f[i][0] = min(f[i][0], f[i-1][1] + dist[a[i-1]][b[i-2]] 
                    + dist[b[i-2]][b[i-1]] + dist[b[i-1]][a[i]]);
                f[i][1] = min(f[i][1], f[i-1][1] 
                    + dist[a[i-1]][b[i-2]] + dist[b[i-2]][a[i]]);
            }
        }
        
        ll res = min(f[k][0] + dist[a[k]][b[k]], 
            f[k][1] + dist[a[k]][b[k-1]] + dist[b[k-1]][b[k]]);

        printf("Case #%d: %lld\n", tt, res);
    }
    return 0;
}
