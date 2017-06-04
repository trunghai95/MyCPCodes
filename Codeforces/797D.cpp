#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val, lef, rig, par;

    Node(): val(-1), lef(-1), rig(-1), par(-1) {}
};

const int INF = 2e9;
const int MAXN = 1e5;
int n, root;
Node a[MAXN+2];
set<int> res;

void dfs(int node, int mx, int mn) {
    if (node == -1) return;

    cout << node << ' ' << a[node].val << ' ' << mx << ' ' << mn << '\n';
    if (a[node].val < mn && a[node].val >= mx) {
        res.erase(a[node].val);
    }
    dfs(a[node].lef, mx, min(mn, a[node].val));
    dfs(a[node].rig, max(mx, a[node].val), mn);
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &a[i].val, &a[i].lef, &a[i].rig);
        res.insert(a[i].val);

        if (a[i].lef != -1) {
            a[a[i].lef].par = i;
        }

        if (a[i].rig != -1) {
            a[a[i].rig].par = i;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (a[i].par == -1) {
            root = i;
            break;
        }
    }

    dfs(root, -INF, INF);

    printf("%d\n", (int)res.size());
    return 0;
}
