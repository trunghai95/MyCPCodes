#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e6;
ll n, m, k;
vector<int> adj[MAXN+2];
bool ck[MAXN+2], ck2[MAXN+2];

void dfs(int u) {
    ck[u] = true;
    for (int i = 0; i < (int)adj[u].size(); ++i)
    if (!ck[adj[u][i]]) {
        dfs(adj[u][i]);
    }
}

int main() {
    scanf("%lld %lld", &n, &m);

    for (int i = 1, u, v; i <= m; ++i) {
        scanf("%d %d", &u, &v);
        if (u == v) {
            ++k;
            ck2[u] = true;
        } else {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    for (int i = 1, cc = 0; i <= n; ++i)
    if (!ck[i] && !adj[i].empty()) {
        dfs(i);
        if (++cc > 1) {
            printf("0\n");
            return 0;
        }
    }

    for (int i = 1; i <= n; ++i)
    if (!ck[i] && ck2[i]) {
        printf("0\n");
        return 0;
    }

    ll res = k * (m - k) + k * (k - 1) / 2;
    for (int i = 1; i <= n; ++i) {
        ll sz = adj[i].size();
        res += sz * (sz - 1) / 2; 
    }

    printf("%lld\n", res);
    return 0;
}
