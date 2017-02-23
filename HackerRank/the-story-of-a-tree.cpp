#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

const int MAXN = 1e5;
int test, n, m, k, cnt, res;
vector<int> adj[MAXN+2];
set<pii> s;

void dfs1(int u, int p) {
    cnt += s.count(pii(p, u));

    for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if (v != p) {
            dfs1(v, u);
        }
    }
}

void dfs2(int u, int p) {
    cnt -= s.count(pii(p, u));
    cnt += s.count(pii(u, p));

    if (cnt >= k) {
        ++res;
    }

    for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if (v != p) {
            dfs2(v, u);
        }
    }

    cnt += s.count(pii(p, u));
    cnt -= s.count(pii(u, p));
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d", &n);

        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
        }

        for (int i = 1, u, v; i < n; ++i) {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        s.clear();

        scanf("%d %d", &m, &k);
        for (int i = 0, u, v; i < m; ++i) {
            scanf("%d %d", &u, &v);
            s.insert(pii(u, v));
        }

        cnt = res = 0;
        dfs1(1, -1);
        dfs2(1, -1);

        if (res == 0) {
            n = 1;
        } else {
            int g = __gcd(res, n);
            res /= g;
            n /= g;
        }

        printf("%d/%d\n", res, n);
    }
    return 0;
}
