#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second

const int MAXN = 100000;
const int LOGMAX = 17;
const int BLKSZ = 250;
const int BLKNUM = MAXN/BLKSZ + 3;

int n, q, a[MAXN+1], cnt[MAXN+1], cc, par[MAXN+1][LOGMAX+1], height[MAXN+1];
int nearSpec[MAXN+1], id[MAXN+1], nSpec;
int u1, v1, u2, v2, specCnt[BLKNUM+1][MAXN+1];
ll specQuery[BLKNUM+1][MAXN+1], res;
pii mp[MAXN+1], p1, p2;
vector<int> adj[MAXN+1];

void dfsInit(const int& p, const int& u) {
    par[u][0] = p;
    height[u] = height[p] + 1;
    for (int i = 1; i <= LOGMAX; ++i)
    if ((par[u][i] = par[par[u][i-1]][i-1]))
        break;
    nearSpec[u] = nearSpec[p];

    if (height[u] % BLKSZ == 0) {
        ++nSpec;
        id[u] = nSpec;
        nearSpec[u] = u;
    }

    for (int i = 0; i < (int)adj[u].size(); ++i) {
        if (adj[u][i] != p)
            dfsInit(u, adj[u][i]);
    }
}

inline int lca(int u, int v) {
    if (height[u] > height[v]) swap(u, v);
    int tmp = LOGMAX;
    while (height[u] < height[v]) {
        for (int i = tmp; i >= 0; --i)
        if (height[par[v][i]] >= height[u]) {
            v = par[v][i];
            tmp = i;
            break;
        }
    }

    if (u == v) return u;

    tmp = LOGMAX;
    while (par[u][0] != par[v][0]) {
        for (int i = tmp; i >= 0; --i)
        if (par[u][i] != par[v][i]) {
            u = par[u][i]; v = par[v][i];
            tmp = i;
            break;
        }
    }

    return par[u][0];
}

inline pii lca2(int u, int v) {
    if (u == v) return pii(u, u);

    if (height[u] > height[v]) swap(u, v);
    int tmp = LOGMAX;
    while (height[u] < height[v] - 1) {
        for (int i = tmp; i >= 0; --i)
        if (height[par[v][i]] > height[u]) {
            v = par[v][i];
            tmp = i;
            break;
        }
    }

    if (par[v][0] == u) {
        return pii(u, v);
    }

    if (height[u] < height[v]) v = par[v][0];

    tmp = LOGMAX;
    while (par[u][0] != par[v][0]) {
        for (int i = tmp; i >= 0; --i)
        if (par[u][i] != par[v][i]) {
            u = par[u][i]; v = par[v][i];
            tmp = i;
            break;
        }
    }

    return pii(par[u][0], v);
}

inline bool isPar(int u, int v) {
    int tmp = LOGMAX;

    while (height[u] < height[v]) {
        for (int i = tmp; i >= 0; --i)
        if (height[par[v][i]] >= height[u]) {
            v = par[v][i];
            tmp = i;
            break;
        }
    }

    return (v == u);
}

void dfsCount(const int& u) {
    for (int spec = 1; spec <= nSpec; ++spec)
        specQuery[spec][u] = specQuery[spec][par[u][0]] + specCnt[spec][u];
    for (int i = 0; i < (int)adj[u].size(); ++i) {
        if (adj[u][i] != par[u][0])
            dfsCount(adj[u][i]);
    }
}

void dfsPreprocess(const int& u) {
    ++cnt[a[u]];
    if (id[u]) {
        for (int i = 1; i <= n; ++i)
            specCnt[id[u]][i] = cnt[a[i]];
    }

    for (int i = 0; i < (int)adj[u].size(); ++i) {
        if (adj[u][i] != par[u][0]) {
            dfsPreprocess(adj[u][i]);
        }
    }
    --cnt[a[u]];
}

inline void up(const int& u, const int& p) {
    for (int i = u; height[i] % BLKSZ; i = par[i][0]) {
        if (i == p) return;
        ++cnt[a[i]];
    }

    for (int i = p; height[i] % BLKSZ; i = par[i][0])
        --cnt[a[i]];
}

inline void down(const int& u, const int& p) {
    for (int i = u; height[i] % BLKSZ; i = par[i][0]) {
        if (i == p) return;
        --cnt[a[i]];
    }
    for (int i = p; height[i] % BLKSZ; i = par[i][0])
        ++cnt[a[i]];
}

inline ll calc(const int& u, const int& p) {
    ll res = 0;
    for (int i = u; height[i] % BLKSZ; i = par[i][0]) {
        if (i == p) return res;
        res += cnt[a[i]];
    }
    for (int i = p; height[i] % BLKSZ; i = par[i][0])
        res -= cnt[a[i]];
    return res;
}

inline int query1_1(const int& v, const int& u) {
    if (!u) return 0;
    return specCnt[id[nearSpec[u]]][v];
}

inline int query1(const int& v, const int& p, const int& u) {
    if (p == u) return (a[p] == a[v] && p != v);
    int res = query1_1(v, u) - query1_1(v, par[p][0]);
    if (isPar(v, u) && height[v] >= height[p])
        --res;
    return res;
}

inline ll query_1(int u, int v) {
    if (!u || !v) return 0;
    ll res = specQuery[id[nearSpec[u]]][v] + specQuery[id[nearSpec[v]]][u] 
        - specQuery[id[nearSpec[u]]][nearSpec[v]];

    return res;
}

inline ll query(const int& p1, const int& u1, const int& p2, const int& u2) {
    ll res = query_1(u1, u2) - query_1(par[p1][0], u2) - query_1(u1, par[p2][0])
        + query_1(par[p1][0], par[p2][0]);

    int p = lca(u1, u2);
    if (height[p] >= height[p1] && height[p] >= height[p2]) {
        res += height[p1] + height[p2] - min(height[p1], height[p2]) 
            - 1 - height[p];
    }
    return res;
}

int main() {
    clock_t st = clock(), en;
    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
        mp[i].F = a[i];
        mp[i].S = i;
    }

    sort(mp+1, mp+1+n);
    for (int i = 1; i <= n; ++i) {
        if (mp[i].F != mp[i-1].F) ++cc;
        a[mp[i].S] = cc;
    }

    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &u1, &v1);
        adj[u1].push_back(v1);
        adj[v1].push_back(u1);
    }

    dfsInit(0, 1);
    dfsPreprocess(1);
    dfsCount(1);

    while (q --> 0) {
        scanf("%d %d %d %d", &u1, &v1, &u2, &v2);
        res = 0;

        if (height[u1] > height[v1]) swap(u1, v1);
        if (height[u2] > height[v2]) swap(u2, v2);

        p1 = lca2(u1, v1);
        p2 = lca2(u2, v2);

        if (u1 == v1) {
            if (u2 == v2) {
                res = (a[u1] == a[u2] && u1 != u2);
            } else {
                ++cnt[a[u1]];
                res = query1(u1, p2.F, u2) + query1(u1, p2.S, v2)
                    + calc(u2, par[p2.F][0]) + calc(v2, par[p2.S][0]);
                --cnt[a[u1]];
            }
        } else if (u2 == v2) {
            ++cnt[a[u2]];
            res = query1(u2, p1.F, u1) + query1(u2, p1.S, v1)
                + calc(u1, par[p1.F][0]) + calc(v1, par[p1.S][0]);
            --cnt[a[u2]];
        } else {
            up(u1, par[p1.F][0]); up(v1, par[p1.S][0]);
            res = query(p1.F, u1, p2.F, u2) + query(p1.F, u1, p2.S, v2)
                + query(p1.S, v1, p2.F, u2) + query(p1.S, v1, p2.S, v2)
                + calc(u2, par[p2.F][0]) + calc(v2, par[p2.S][0]);
            down(u1, par[p1.F][0]); down(v1, par[p1.S][0]);
        }

        printf("%lld\n", res);
    }

    en = clock();
    cerr << 1.0*(en - st)/CLOCKS_PER_SEC << '\n';
    return 0;
}
