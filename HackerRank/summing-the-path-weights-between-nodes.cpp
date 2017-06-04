#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,ll> pil;

const int MAXN = 1e5;
int n, color[MAXN+2];
vector<pil> adj[MAXN+2];
ll sum1, cnt1[MAXN+2], cnt[MAXN+2], res;

void visit(int u, int p) {
    cnt[u] = 1;
    cnt1[u] = color[u];

    for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i].first;
        ll w = adj[u][i].second;

        if (v == p) continue;

        visit(v, u);
        ll tmp = cnt1[v] * (n - sum1 - cnt[v] + cnt1[v]);
        tmp += (cnt[v] - cnt1[v]) * (sum1 - cnt1[v]);
        res += tmp * w;

        cnt[u] += cnt[v];
        cnt1[u] += cnt1[v];
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", color+i);
        sum1 += color[i];
    }

    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d %d %lld", &u, &v, &res);
        adj[u].push_back(pil(v, res));
        adj[v].push_back(pil(u, res));
    }

    res = 0;

    visit(1, -1);

    printf("%lld\n", res);
    return 0;
}
