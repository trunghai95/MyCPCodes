#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int n, m, W, w[MAXN+2], b[MAXN+2], ww[MAXN+2], bb[MAXN+2];
int res[MAXN+2], cache[MAXN+2], cnt;
bool ck[MAXN+2];
vector<int> adj[MAXN+2], cpn[MAXN+2];

void bfs(int s, int id) {
    queue<int> q;
    q.push(s);
    ck[s] = true;
    ww[id] += w[s];
    bb[id] += b[s];
    cpn[id].push_back(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i];
            if (!ck[v]) {
                q.push(v);
                ck[v] = true;
                ww[id] += w[v];
                bb[id] += b[v];
                cpn[id].push_back(v);
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &W);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", w+i);
    }

    for (int i = 1; i <= n; ++i) {
        scanf("%d", b+i);
    }

    for (int i = 1, u, v; i <= m; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
    if (!ck[i]) {
        bfs(i, ++cnt);
    }

    for (int i = 1; i <= cnt; ++i) {
        memset(cache, 0, sizeof(cache));

        for (int j = ww[i]; j <= W; ++j)
            cache[j] = res[j-ww[i]] + bb[i];

        for (int j = 0; j < (int)cpn[i].size(); ++j) {
            int u = cpn[i][j];
            for (int k = w[u]; k <= W; ++k)
                cache[k] = max(cache[k], res[k-w[u]] + b[u]);
        }

        for (int j = 0; j <= W; ++j)
            res[j] = max(res[j], cache[j]);
    }

    int rr = 0;
    for (int i = 0; i <= W; ++i)
        rr = max(rr, res[i]);
    printf("%d\n", rr);

    return 0;
}
