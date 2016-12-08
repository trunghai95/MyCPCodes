#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
int n, a[MAXN+2], b[MAXN+2];
vector<int> adj[MAXN*2+2];
int c[MAXN*2+2];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    c[s] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i];
            if (c[v] == 0) {
                c[v] = 3 - c[u];
                q.push(v);
            }
        }
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", a+i, b+i);
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
        adj[i*2].push_back(i*2-1);
        adj[i*2-1].push_back(i*2);
    }

    int nn = n << 1;
    for (int i = 1; i <= nn; ++i)
    if (!c[i])
        bfs(i);

    for (int i = 1; i <= n; ++i) {
        printf("%d %d\n", c[a[i]], c[b[i]]);
    }
    return 0;
}
