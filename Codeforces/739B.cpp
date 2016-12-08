#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,ll> pil;
#define F first
#define S second

const int MAXN = 200000;
const int MAXLOG = 18;
int n, par[MAXN+1][MAXLOG+1], cnt[MAXN+1];
ll a[MAXN+1], dist[MAXN+1];
vector<pil> adj[MAXN+1];

void dfs(int u = 1, int p = -1) {
    par[u][0] = p;

    for (int i = 1; i <= MAXLOG && par[u][i-1] != -1; ++i) {
        par[u][i] = par[par[u][i-1]][i-1];
    }

    int v = u;
    for (int i = MAXLOG; i >= 0; --i) {
        if (par[v][i] != -1 && dist[u] - dist[par[v][i]] <= a[u])
            v = par[v][i];
    }

    if (v != u) {
        ++cnt[par[u][0]];
        if (par[v][0] != -1)
            --cnt[par[v][0]];
    }

    for (int i = 0; i < (int)adj[u].size(); ++i) {
        v = adj[u][i].F;
        dist[v] = dist[u] + adj[u][i].S;
        dfs(v, u);
    }
}

void dfs2(int u = 1) {
    for (int i = 0; i < (int)adj[u].size(); ++i)
        dfs2(adj[u][i].F), cnt[u] += cnt[adj[u][i].F];
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%lld", a+i);

    for (int i = 2, u, w; i <= n; ++i) {
        scanf("%d %d", &u, &w);
        adj[u].push_back(pil(i, w));
    }

    memset(par, -1, sizeof(par));

    dfs();
    dfs2();

    for (int i = 1; i <= n; ++i)
        printf("%d ", cnt[i]);
    printf("\n");
    return 0;
}
