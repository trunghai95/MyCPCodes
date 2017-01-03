#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 2e18;
const int MAXN = 200000;

struct Node {
    vector<int> adj;
    ll val, sum, maxSum, res;
    int par;

    Node() {
        par = -1;
        val = sum = 0;
        maxSum = res = -INF;
    }
};

int n;
Node node[MAXN+3];

void dfs(int u) {
    for (int i = 0; i < (int)node[u].adj.size(); ++i) {
        int v = node[u].adj[i];
        if (v != node[u].par) {
            node[v].par = u;
            dfs(v);
            node[u].sum += node[v].sum;
        }
    }

    node[u].sum += node[u].val;
}

void solve(int u) {
    ll mx1 = -INF, mx2 = -INF;
    node[u].maxSum = node[u].sum;

    for (int i = 0; i < (int)node[u].adj.size(); ++i) {
        int v = node[u].adj[i];
        if (v != node[u].par) {
            solve(v);
            if (node[v].maxSum > mx1) {
                mx2 = mx1;
                mx1 = node[v].maxSum;
            } else if (node[v].maxSum > mx2) {
                mx2 = node[v].maxSum;
            }
            node[u].maxSum = max(node[u].maxSum, node[v].maxSum);
            node[u].res = max(node[u].res, node[v].res);
        }
    }

    if (mx2 > -INF) {
        node[u].res = max(node[u].res, mx1 + mx2);
    }
}


int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &node[i].val);
    }

    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        node[u].adj.push_back(v);
        node[v].adj.push_back(u);
    }

    dfs(1);
    solve(1);

    if (node[1].res == -INF) {
        printf("Impossible\n");
    } else {
        printf("%lld\n", node[1].res);
    }
    return 0;
}
