#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
int n, c[MAXN+2], root;
vector<int> adj[MAXN+2];
bool ck[MAXN+2];

void bfs1() {
    queue<int> q;
    ck[1] = true;
    q.push(1);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i];
            if (ck[v]) continue;
            if (c[v] == c[u]) {
                ck[v] = true;
                q.push(v);
            } else if (root == 0) {
                root = u;
            } else if (root != u) {
                printf("NO\n");
                exit(0);
            }
        }
    }
}

void bfs2(int s) {
    queue<int> q;
    ck[s] = true;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i];
            if (ck[v]) continue;
            if (c[v] == c[u]) {
                ck[v] = true;
                q.push(v);
            } else {
                printf("NO\n");
                exit(0);
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

    for (int i = 1; i <= n; ++i)
        scanf("%d", c+i);

    bfs1();

    vector<int> rr;
    for (int i = 0; i < (int)adj[root].size(); ++i) {
        if (!ck[adj[root][i]]) {
            rr.push_back(adj[root][i]);
        }
    }

    if (rr.empty()) {
        printf("YES\n1\n");
        return 0;
    } else if (rr.size() == 1) {
        root = rr[0];
    }

    ck[root] = true;

    for (int i = 1; i <= n; ++i)
    if (!ck[i])
        bfs2(i);

    printf("YES\n%d\n", root);
    return 0;
}
