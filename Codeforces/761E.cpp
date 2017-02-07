#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second

const int MAXN = 30;
int n;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> adj[MAXN+2];
pll res[MAXN+2];

void dfs(int u, int p, ll val, int d) {
    ll val2 = val/2;
    d = (d + 2) % 4;
    for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if (v == p) continue;

        d = (d + 1) % 4;
        res[v].F = res[u].F + val * dx[d];
        res[v].S = res[u].S + val * dy[d];
        dfs(v, u, val2, d);
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
    if ((int)adj[i].size() > 4) {
        printf("NO\n");
        return 0;
    }

    dfs(1, -1, 1LL << 30, 0);

    printf("YES\n");
    for (int i = 1; i <= n; ++i)
        printf("%lld %lld\n", res[i].F, res[i].S);
    return 0;
}
