#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, dist[3][200010];
vector<int> adj[200010][2];

void bfs(int p, int s, int dir) {
    dist[p][s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < (int)adj[u][dir].size(); ++i) {
            int v = adj[u][dir][i];
            if (dist[p][v] == -1) {
                dist[p][v] = dist[p][u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    memset(dist, -1, sizeof(dist));
    scanf("%d %d %d %d", &n, &m, &a, &b);

    for (int i = 0, u, v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        adj[u][0].push_back(v);
        adj[v][1].push_back(u);
    }

    bfs(0, 0, 0);
    bfs(1, a, 1);
    bfs(2, b, 1);

    int res = 2e9;
    for (int i = 0; i <= n; ++i)
    if (dist[0][i] != -1 && dist[1][i] != -1 && dist[2][i] != -1) {
        res = min(res, dist[0][i] + dist[1][i] + dist[2][i]);
    }
    printf("%d\n", res);
    return 0;
}
