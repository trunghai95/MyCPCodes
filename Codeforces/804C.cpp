#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5;
int n, m, s, x, res[MAXN+2], ck[MAXN+2], resc, visited[MAXN+2];
vector<int> ic[MAXN+2], adj[MAXN+2];

void process(int p) {
    for (int i = 0; i < (int)ic[p].size(); ++i) {
        int u = ic[p][i];
        if (res[u]) {
            ck[res[u]] = p;
        }
    }

    int c = 1;
    for (int i = 0; i < (int)ic[p].size(); ++i) {
        int u = ic[p][i];
        if (res[u]) {
            continue;
        }
        while (ck[c] == p) ++c;
        res[u] = c;
        ++c;
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &s);
        resc = max(resc, s);

        while (s --> 0) {
            scanf("%d", &x);
            ic[i].push_back(x);
        }
    }

    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        process(u);

        for (int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i];
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    if (!resc) resc = 1;

    printf("%d\n", resc);
    for (int i = 1; i <= m; ++i) {
        if (!res[i]) res[i] = 1;
        printf("%d ", res[i]);
    }

    printf("\n");
    return 0;
}
