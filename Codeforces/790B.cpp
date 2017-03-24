#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200000;
const int MAXK = 5;
int n, k;
vector<int> adj[MAXN+2];
ll dp[MAXN+2][MAXK+2], res;

int dfs(int u, int p) {
    dp[u][0] = 1;
    ll cnt = 1;

    for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if (v == p) {
            continue;
        }

        int ret = dfs(v, u);

        res += (ll) ret * (n - ret);
        cnt += ret;

        for (int j1 = 0; j1 < k; ++j1)
        for (int j2 = 0; j2 < k; ++j2) {
            ll x = (k*3 - j1 - j2 - 1) % k;
            res += x * dp[u][j1] * dp[v][j2];
        }

        for (int j = 0; j < k; ++j) {
            dp[u][(j+1) % k] += dp[v][j];
        }
    }

    return cnt;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);
    printf("%lld\n", res/k);
    return 0;
}
