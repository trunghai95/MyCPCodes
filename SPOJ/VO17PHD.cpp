#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,ll> pil;
struct HeapItem {
    int id;
    ll dist, val;
    HeapItem(int a, ll b, ll c): id(a), dist(b), val(c) {}
    bool operator<(const HeapItem &x) const {
        if (x.dist == this->dist) {
            return x.val > this->val;
        }
        return x.dist < this->dist;
    }
};

const int MAXN = 100000;
const ll INF = 1e18;
int n, m, u, v;
ll p[MAXN+2], c, dis[MAXN+2], val[MAXN+2];
vector<pil> adj[MAXN+2];
bool ck[MAXN+2];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%lld", p+i);

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %lld", &u, &v, &c);
        adj[u].push_back(pil(v, c));
        adj[v].push_back(pil(u, c));
    }

    priority_queue<HeapItem> heap;
    fill(dis+1, dis+1+n, INF);
    fill(val+1, val+1+n, -1);
    heap.push(HeapItem(1, 0, p[1]));
    dis[1] = 0;
    val[1] = p[1];

    while (!heap.empty()) {
        HeapItem u = heap.top(); heap.pop();
        if (ck[u.id]) continue;
        ck[u.id] = true;
        if (u.id == n) break;

        for (int i = 0; i < (int)adj[u.id].size(); ++i) {
            int v = adj[u.id][i].first;
            ll d = adj[u.id][i].second;
            if (ck[v]) continue;
            if (dis[u.id] + d < dis[v]) {
                dis[v] = dis[u.id] + d;
                val[v] = val[u.id] + p[v];
                heap.push(HeapItem(v, dis[v], val[v]));
            } else if (dis[u.id] + d == dis[v] && val[u.id] + p[v] > val[v]) {
                val[v] = val[u.id] + p[v];
                heap.push(HeapItem(v, dis[v], val[v]));
            }
        }
    }

    if (val[n] == -1) printf("impossible\n");
    else
        printf("%lld %lld\n", dis[n], val[n]);
    return 0;
}
