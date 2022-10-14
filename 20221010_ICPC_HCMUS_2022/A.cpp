#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
int n, m, u, v, dist[MAXN];
vector<int> adj[MAXN];
queue<int> q;

int main() {
    scanf("%d %d", &n, &m);
    while (m --> 0) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        u = q.front();
        q.pop();
        if (u == n) {
            break;
        }
        for (int i = 0; i < adj[u].size(); i++) {
            v = adj[u][i];
            if (dist[v] >= 0) {
                continue;
            }
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    printf("%d\n", dist[n] - 1);
    return 0;
}