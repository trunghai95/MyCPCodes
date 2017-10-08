#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5;
int n, c[MAXN+2];
ll cnt[2];
vector<int> adj[MAXN+2];

void bfs() {
    memset(c, -1, sizeof(c));
    queue<int> q;
    q.push(1);
    c[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ++cnt[c[u]];

        for (int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i];
            if (c[v] == -1) {
                c[v] = 1 - c[u];
                q.push(v);
            }
        }
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs();
    ll res = cnt[0]*cnt[1] - n + 1;
    printf("%lld\n", res);
    return 0;
}
