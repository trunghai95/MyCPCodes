#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
    int u, v;
    ll w;
};

bool cmp(const Edge &x, const Edge &y) {
    return x.w < y.w;
}

const int MAXN = 1e4;
const int MAXM = 1e6;
int test, n, m, s, p[MAXN+2], rk[MAXN+2], x;
ll l;
vector<int> adj[MAXN+2];
Edge e[MAXM+2];

int find(int x) {
    return (x == p[x]) ? x : (p[x] = find(p[x]));
}

bool join(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return false;

    if (rk[x] > rk[y]) {
        swap(x, y);
    }

    p[x] = y;
    rk[y] += x;
    return true;
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d %d %lld %d", &n, &m, &l, &s);

        for (int i = 1; i <= n; ++i) {
            p[i] = i;
            rk[i] = 1;
        }

        scanf("%d", &x);
        int g = x;
        for (int i = 2; i <= s; ++i) {
            scanf("%d", &x);
            p[x] = g;
        }

        for (int i = 1; i <= m; ++i) {
            scanf("%d %d %lld", &e[i].u, &e[i].v, &e[i].w);
        }

        sort(e+1, e+1+m, cmp);

        ll res = l * (n - s);
        for (int i = 1; i <= m; ++i) {
            if (join(e[i].u, e[i].v)) {
                res += e[i].w;
            }
        }

        printf("%lld\n", res);
    }
    return 0;
}
