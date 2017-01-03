#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
int n, k, cen;
vector<int> adj[MAXN+2], vs[2];
bool ck[MAXN+2];

int dfs(int u, int p = -1) {
    int ret = 0;

    if (ck[u]) {
        if ((int)vs[0].size() < k)
            vs[0].push_back(u);
        else
            vs[1].push_back(u);
        ret = 1;
    }

    for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if (v == p)
            continue;
        int tmp = dfs(v, u);
        ret += tmp;
        if (ret >= k && !cen)
            cen = u;
    }

    return ret;
}

int main() {

    scanf("%d %d", &n, &k);

    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0, u, v; i < k; ++i) {
        scanf("%d %d", &u, &v);
        ck[u] = ck[v] = true;
    }

    dfs(1);

    printf("1\n%d\n", cen);
    for (int i = 0; i < k; ++i)
        printf("%d %d %d\n", vs[0][i], vs[1][i], cen);
    return 0;
}
