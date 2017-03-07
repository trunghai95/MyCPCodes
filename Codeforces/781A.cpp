#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int n, color[MAXN+2], k;
vector<int> adj[MAXN+2];

void dfs(int u, int p) {
    k = max(k, color[u]);
    int c1 = color[u];
    int c2 = (p == -1 ? 0 : color[p]);

    int c = 1;
    for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if (v == p) continue;
        while (c == c1 || c == c2) ++c;
        color[v] = c;
        dfs(v, u);
        ++c;
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    color[1] = 1;
    dfs(1, -1);

    printf("%d\n", k);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", color[i]);
    }
    printf("\n");
    return 0;
}
