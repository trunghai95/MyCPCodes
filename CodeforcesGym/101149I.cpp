#include <bits/stdc++.h>

using namespace std;

int n, m, u, v;
vector<int> adj[200010];
bool ck[200010];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int mn = 2e9, mni = 0;

    for (int i = 1; i <= n; ++i)
    if ((int)adj[i].size() < mn) {
        mn = adj[i].size();
        mni = i;
    }

    ck[mni] = true;
    for (int i = 0; i < (int)adj[mni].size(); ++i) {
        ck[adj[mni][i]] = true;
    }

    for (int i = 1; i <= n; ++i) {
        printf("%d ", ck[i]?0:1);
    }
    printf("\n");
    return 0;
}
