// WA

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

const int MAXN = 100000;
int test, n, m, k, dist[MAXN+5];
vector<pii> adj[MAXN+5];
bool inQ[MAXN+5];

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d %d %d", &n, &m, &k);

        for (int i = 1; i <= n; ++i)
            adj[i].clear();
        memset(inQ, 0, (n+1)*sizeof(bool));
        memset(dist, -1, (n+1)*sizeof(int));

        for (int i = 0, u, v, w; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(pii(v, w));
            adj[v].push_back(pii(u, w));
        }

        queue<int> q;
        q.push(n);
        dist[n] = 0;
        inQ[n] = true;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            inQ[u] = false;

            for (int i = 0; i < (int)adj[u].size(); ++i) {
                int v = adj[u][i].F;
                int w = adj[u][i].S;
                if (dist[v] == -1 || dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    if (!inQ[v]) {
                        q.push(v);
                        inQ[v] = true;
                    }
                }
            }
        }

        int res = dist[n];
        if (res == -1)
            res = k*n;
        else
            res = min(res, k*n);
        printf("%d.000000000000\n", res);
    }
    return 0;
}
