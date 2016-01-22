#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 400010;
const LL MAXX = (1LL << 61) - 2;

int n, m, c[MAXN], lazy[MAXN*4], u, v, lef[MAXN], rig[MAXN], arr[MAXN], cnt;
vector<int> adj[MAXN];

void dfs(int u)
{
    lef[u] = ++cnt;
    arr[cnt] = u;

    for (int i = 0; i < adj[u].size(); ++i)
    if (!lef[adj[u][i]])
        dfs(adj[u][i]);

    rig[u] = cnt;
}

void build_tree(int node, int l, int r)
{
    if (r == l) { lazy[node] = c[arr[l]]; return; }

    int m = ((l + r) >> 1);
    build_tree(node << 1, l, m);
    build_tree((node << 1) | 1, m+1, r);
}

void update(int node, int l, int r, int ll, int rr, int val)
{
    if (ll > r || rr < l) return;
    if (r == l || (l >= ll && r <= rr)) { lazy[node] = val; return; }

    if (lazy[node])
    {
        lazy[node<<1] = lazy[(node<<1)|1] = lazy[node];
        lazy[node] = 0;
    }

    int m = ((l + r) >> 1);
    update(node << 1, l, m, ll, rr, val);
    update((node << 1) | 1, m + 1, r, ll, rr, val);
}

LL get(int node, int l, int r, int ll, int rr)
{
    if (ll > r || rr < l) return 0;
    if (r == l)
        return (1LL << lazy[node]);

    if (lazy[node])
    {
        if (l >= ll && r <= rr)
            return (1LL << lazy[node]);

        lazy[node<<1] = lazy[(node<<1)|1] = lazy[node];
        lazy[node] = 0;
    }

    int m = ((l + r) >> 1);
    LL res1 = get(node << 1, l, m, ll, rr);
    if (res1 == MAXX)
        return res1;
    return res1 | get((node << 1) | 1, m + 1, r, ll, rr);
}

int countBit(LL x)
{
    int res = 0;
    while (x)
        res += (x & 1), x >>= 1;
    return res;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i)
        scanf("%d", c+i);

    for (int i = 1; i < n; ++i)
    {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    build_tree(1, 1, n);

    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &cnt);
        if (cnt == 1)
        {
            scanf("%d %d", &u, &v);
            update(1, 1, n, lef[u], rig[u], v);
        }
        else
        {
            scanf("%d", &u);
            printf("%d\n", countBit(get(1, 1, n, lef[u], rig[u])));
        }
    }
    return 0;
}
