#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
int n, c[MAXN+5], nCpn, c2[MAXN+5];
vector<int> adj[MAXN+5], adj2[MAXN+5];

struct cmp {
    bool operator()(int x, int y) {
        return adj2[x].size() < adj2[y].size();
    }
};
priority_queue<int, vector<int>, cmp> heap;

void bfs(int s, int p) {
    cout << p << ": ";
    queue<int> q;
    q.push(s);
    c2[s] = p;

    while (!q.empty()) {
        int u = q.front();
        cout << u << ' ';
        q.pop();

        for (int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i];
            if (c2[v] != p) {
                if (c[v] == c[u]) {
                    c2[v] = p;
                    q.push(v);
                } else if (c2[v]) {
                    adj2[c2[v]].push_back(p);
                    adj2[p].push_back(c2[v]);
                }
            }
        }
    }
    cout << '\n';
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d", c+i);

    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
    if (!c2[i]) {
        bfs(i, ++nCpn);
    }
    for (int i = 1; i <= nCpn; ++i)
        c[i] = i, heap.push(i);

    int res = 0;
    while (!heap.empty()) {
        int u = heap.top(); heap.pop();

        if (c[u] != u) continue;
        cout << "++" << u << '\n';

        ++res;
        int tmp = adj2[u].size();
        for (int i = 0; i < tmp; ++i) {
            int v = adj2[u][i];
            cout << v << ' ';
            c[adj2[u][i]] = u;
            for (int j = 0; j < (int)adj2[v].size(); ++j)
            if (adj2[v][j] != u)
                adj2[u].push_back(adj2[v][j]);
            adj2[v].clear();
        }
        adj2[u] = vector<int>(adj2[u].begin() + tmp, adj2[u].end());

        if (!adj2[u].empty())
            heap.push(u);
        cout << '\n';
    }

    printf("%d\n", res - 1);
    return 0;
}
