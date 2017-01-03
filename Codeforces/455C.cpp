#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300000;
int n, m, q, p[MAXN+3], rk[MAXN+3], dia[MAXN+3], type, x, y, dist[MAXN+3];
bool flag[MAXN+3];
vector<int> adj[MAXN+3];

int ceil(int n) {
    if (!n) return 0;
    return (n-1)/2 + 1;
}

int find(int x) {
    return (p[x] == x ? x : (p[x] = find(p[x])));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rk[x] < rk[y]) swap(x, y);

    rk[x] += rk[y];
    p[y] = x;
}

void join2(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rk[x] < rk[y]) swap(x, y);

    dia[x] = max(max(dia[x], dia[y]), ceil(dia[x]) + ceil(dia[y]) + 1);
    rk[x] += rk[y];
    p[y] = x;
}

int calDia(int p) {
    queue<int> q;
    q.push(p);
    flag[p] = true;
    dist[p] = 0;
    int u, v;

    while (!q.empty()) {
        u = q.front(); q.pop();
        for (int i = 0; i < (int)adj[u].size(); ++i) {
            v = adj[u][i];
            if (!flag[v]) {
                flag[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    q.push(u);
    flag[u] = false;
    dist[u] = 0;

    while (!q.empty()) {
        u = q.front(); q.pop();
        for (int i = 0; i < (int)adj[u].size(); ++i) {
            v = adj[u][i];
            if (flag[v]) {
                flag[v] = false;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist[u];
}

int main() {
    scanf("%d %d %d", &n, &m, &q);

    for (int i = 1; i <= n; ++i)
        p[i] = i, rk[i] = 1;

    for (int i = 1; i <= m; ++i) {
        scanf("%d %d", &x, &y);
        join(x, y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i)
    if (find(i) == i) {
        dia[i] = calDia(i);
    }

    while (q --> 0) {
        scanf("%d %d", &type, &x);
        if (type == 1) {
            printf("%d\n", dia[find(x)]);
        } else {
            scanf("%d", &y);
            join2(x, y);
        }
    }
    return 0;
}
