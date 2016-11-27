#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int n1, n2, dist[MAXN+3], pairU[MAXN+3], pairV[MAXN+3];
int x[MAXN+3], y[MAXN+3];
vector<int> adj[MAXN+3];

bool bfs() {
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    int mx = -1;

    for (int u = 1; u <= n1; ++u)
    if (pairU[u] == -1) {
        dist[u] = 0;
        q.push(u);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i];
            if (pairV[v] == -1) { mx = dist[u]; return true; }
            else if (dist[pairV[v]] == -1) {
                q.push(pairV[v]);
                dist[pairV[v]] = dist[u] + 1;
            }
        }
    }

    return false;
}

bool dfs(int u) {
    for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if (pairV[v] == -1 || (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v]))) {
            pairU[u] = v;
            pairV[v] = u;
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
        for (int u = 1; u <= n1; ++u)
        if (pairU[u] == -1 && dfs(u))
            ++res;
    }

    return res;
}

int main() {
    scanf("%d %d", &n1, &n2);

    for (int i = 1; i <= n1; ++i)
        scanf("%d %d", x+i, y+i);

    for (int i = 1, u, v; i <= n2; ++i) {
        scanf("%d %d", &u, &v);
        for (int j = 1; j <= n1; ++j)
        if (u > x[j] && v <= y[j])
            adj[j].push_back(i);
    }

    printf("%d\n", maxMatching());
    return 0;
}
