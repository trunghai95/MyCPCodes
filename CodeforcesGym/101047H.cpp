#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int test, n, m, n1, n2, pairU[MAXN+5], pairV[MAXN+5], id[MAXN+5], dist[MAXN+5];
bool side[MAXN+5];
vector<int> adj[MAXN+5], adj2[MAXN+5];

void partite() {
    n1 = n2 = 0;
    memset(id, 0, sizeof(id));
    queue<int> q;
    q.push(1);
    id[1] = ++n1;
    side[1] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < (int)adj2[u].size(); ++i) {
            int v = adj2[u][i];
            if (!id[v]) {
                if (side[u]) {
                    id[v] = ++n1;
                    side[v] = 0;
                } else {
                    id[v] = ++n2;
                    side[v] = 1;
                }
                q.push(v);
            }
        }
    }

    for (int u = 1; u <= n; ++u)
    if (!side[u]) {
        for (int i = 0; i < (int)adj2[u].size(); ++i) {
            int v = adj2[u][i];
            adj[id[u]].push_back(id[v]);
        }
    }
}

bool bfs() {
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    for (int u = 1; u <= n1; ++u)
    if (pairU[u] == -1)
        q.push(u), dist[u] = 0;
    int mx = -1;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        if (mx != -1 && dist[u] >= mx) continue;

        for (int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i];
            if (pairV[v] == -1) mx = dist[u];
            else if (dist[pairV[v]] == -1) {
                q.push(pairV[v]);
                dist[pairV[v]] = dist[u] + 1;
            }
        }
    }

    return (mx != -1);
}

bool dfs(int u) {
    for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if (pairV[v] == -1 || (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v]))) {
            pairV[v] = u;
            pairU[u] = v;
            return true;
        }
    }
    dist[u] = -1;
    return false;
}

int maxMatching() {
    memset(pairU, -1, sizeof(pairU));
    memset(pairV, -1, sizeof(pairV));
    int res = 0;
    while (bfs()) {
        for (int u = 1; u <= n1; ++u) {
            if (pairU[u] == -1 && dfs(u)) {
                ++res;
            }
        }
    }
    return res;
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d %d", &n, &m);

        for (int i = 1; i <= n; ++i)
            adj[i].clear(), adj2[i].clear();

        for (int i = 0, u, v; i < m; ++i) {
            scanf("%d %d", &u, &v);
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        partite();

        printf("%d\n", n - maxMatching());
    }
    return 0;
}
