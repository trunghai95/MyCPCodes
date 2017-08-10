#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5;
int test, n, pos[3], h[MAXN+2], par[MAXN+2];
ll a, b, c;
vector<int> adj[MAXN+2];

void dfs(int u, int p) {
    par[u] = p;
    if (p != -1) {
        h[u] = h[p] + 1;
    }

    for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if (v != p) {
            dfs(v, u);
        }
    }
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
        }

        scanf("%d %lld %lld %lld %d %d %d", &n, &a, &b, &c, pos, pos+1, pos+2);

        for (int i = 1, u, v; i < n; ++i) {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, -1);
        for (int i = 1; i <= n; ++i) {
            cout << i << ' ' << par[i] << ' ' << h[i] << ' ' << adj[i].size() << '\n';
        }
        ll res = 0;

        int m = min(h[pos[0]], min(h[pos[1]], h[pos[2]]));

        for (int i = 0; i < 3; ++i)
        while (h[pos[i]] > m) {
            res += a;
            pos[i] = par[pos[i]];
            cout << pos[0] << ' ' << pos[1] << ' ' << pos[2] << ' ' << res << '\n';
        }

        while (pos[0] != 1) {
            if (pos[0] == pos[1] && pos[0] == pos[2]) {
                res += min(a*3, min(a+b, c));
            } else if (pos[0] == pos[1] || pos[1] == pos[2] || pos[0] == pos[2]) {
                res += min(b, a*2) + a;
            } else {
                res += a*3;
            }
            pos[0] = par[pos[0]];
            pos[1] = par[pos[1]];
            pos[2] = par[pos[2]];
            cout << pos[0] << ' ' << pos[1] << ' ' << pos[2] << ' ' << res << '\n';
        }

        printf("%lld\n", res);
    }

    return 0;
}
