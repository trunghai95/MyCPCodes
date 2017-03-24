#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,ll> pil;
#define F first
#define S second

const int MAXN = 100000;
const int OFFSET1 = MAXN;
const int OFFSET2 = MAXN * 5 + 5;
int n, m, s, type, a, b, c;
vector<pil> adj[MAXN*10];
ll dist[MAXN*10], w;
bool ck[MAXN*10];

struct cmp {
    bool operator()(pil x, pil y) {
        return x.S > y.S;
    }
};

void init(int node, int lef, int rig) {
    if (lef == rig) {
        adj[node + OFFSET1].push_back(pil(lef, 0));
        adj[lef].push_back(pil(node + OFFSET2, 0));
        return;
    }

    int lnode = node*2;
    int rnode = node*2 + 1;
    int mid = (lef + rig) / 2;

    adj[node + OFFSET1].push_back(pil(lnode + OFFSET1, 0));
    adj[node + OFFSET1].push_back(pil(rnode + OFFSET1, 0));
    adj[lnode + OFFSET2].push_back(pil(node + OFFSET2, 0));
    adj[rnode + OFFSET2].push_back(pil(node + OFFSET2, 0));

    init(lnode, lef, mid);
    init(rnode, mid+1, rig);
}

void add1(int node, int lef, int rig, int u, int l, int r, ll w) {
    if (lef > r || rig < l) {
        return;
    }

    if (lef >= l && rig <= r) {
        adj[u].push_back(pil(node + OFFSET1, w));
        return;
    }

    int lnode = node*2;
    int rnode = node*2 + 1;
    int mid = (lef + rig) / 2;

    add1(lnode, lef, mid, u, l, r, w);
    add1(rnode, mid+1, rig, u, l, r, w);
}

void add2(int node, int lef, int rig, int u, int l, int r, ll w) {
    if (lef > r || rig < l) {
        return;
    }

    if (lef >= l && rig <= r) {
        adj[node + OFFSET2].push_back(pil(u, w));
        return;
    }

    int lnode = node*2;
    int rnode = node*2 + 1;
    int mid = (lef + rig) / 2;

    add2(lnode, lef, mid, u, l, r, w);
    add2(rnode, mid+1, rig, u, l, r, w);
}

void solve() {
    memset(dist, -1, sizeof(dist));

    priority_queue<pil, vector<pil>, cmp> heap;
    dist[s] = 0;
    heap.push(pil(s, 0));

    while (!heap.empty()) {
        pil u = heap.top();
        heap.pop();

        if (ck[u.F]) continue;
        ck[u.F] = true;

        for (int i = 0; i < (int)adj[u.F].size(); ++i) {
            pil v(adj[u.F][i].F, u.S + adj[u.F][i].S);

            if (dist[v.F] == -1 || dist[v.F] > v.S) {
                dist[v.F] = v.S;
                heap.push(v);
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &s);
    init(1, 1, n);

    while (m --> 0) {
        scanf("%d %d", &type, &a);
        if (type == 1) {
            scanf("%d %lld", &b, &w);
            adj[a].push_back(pil(b, w));
        } else if (type == 2) {
            scanf("%d %d %lld", &b, &c, &w);
            add1(1, 1, n, a, b, c, w);
        } else {
            scanf("%d %d %lld", &b, &c, &w);
            add2(1, 1, n, a, b, c, w);
        }
    }

    solve();
    for (int i = 1; i <= n; ++i) {
        printf("%lld ", dist[i]);
    }
    printf("\n");

    return 0;
}
