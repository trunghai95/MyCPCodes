#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w;

    bool operator<(const Edge& other) const {
        return this->w > other.w;
    }
};

const int MAXM = 100000;
const int MAXN = 10000;
int test, n, m, p[MAXN+5], rk[MAXN+5];
Edge e[MAXM+5];

int find(int x) {
    return (p[x] == x ? x : (p[x] = find(p[x])));
}

bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return false;

    if (rk[x] < rk[y])
        swap(x, y);

    p[y] = x;
    rk[x] += rk[y];
    return true;
}

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= m; ++i) {
            scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
        }

        for (int i = 1; i <= n; ++i)
            p[i] = i, rk[i] = 1;

        sort(e+1, e+1+m);
        int res1 = 0, res2 = 0;

        for (int i = 1; i <= m; ++i) {
            if (!join(e[i].u, e[i].v))
                res1 += e[i].w, res2 = max(res2, e[i].w);
        }

        printf("Case #%d: %d %d\n", tt, res1, res2);
    }
    return 0;
}
