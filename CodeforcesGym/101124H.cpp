#include <bits/stdc++.h>

using namespace std;

int n, k, x[100010], y[100010], fi[100010], dist[100010], pos[100010];
vector<int> v[100010];

void proc(int start, int u, int d) {
    if (start == u && d > 0) {
        return;
    }

    fi[u] = start;
    dist[u] = d;

    v[start].push_back(u);
    proc(start, pos[y[u]], d+1);
}

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", x+i, y+i);
        pos[x[i]] = i;
    }

    for (int i = 1; i <= n; ++i)
    if (fi[i] == 0) {
        proc(i, i, 0);
    }

    for (int i = 1, a, b; i <= k; ++i) {
        scanf("%d %d", &a, &b);
        b += dist[a];
        a = fi[a];
        b %= v[a].size();
        printf("%d\n", v[a][b]);
    }
    return 0;
}