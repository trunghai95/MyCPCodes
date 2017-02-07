#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10000;
int n, m, a[MAXN+2];
vector<int> adj[MAXN+2];
bool ck[MAXN+2];

bool bfs(int s) {
    int sum = 0;
    queue<int> q;
    ck[s] = true;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        sum += a[u];

        for (int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i];
            if (!ck[v]) {
                ck[v] = true;
                q.push(v);
            }
        }
    }

    return (sum == 0);
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i)
        scanf("%d", a+i);

    for (int i = 0, u, v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i)
    if (!ck[i]) {
        if (!bfs(i)) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }

    printf("POSSIBLE\n");
    return 0;
}
