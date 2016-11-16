#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4;
int n, m, arr[MAXN+5];
vector<int> adj[MAXN+5], res;
bool ck[MAXN+5];

bool cmp(const int& x, const int& y) {
    return adj[x].size() < adj[y].size();
}

void Try(int u) {
    memset(ck, 0, sizeof(ck));
    vector<int> tmp;
    tmp.push_back(u);
    ck[u] = true;

    while (true) {
        int best = 0;
        for (int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i];
            if (!ck[v]) {
                best = v;
                break;
            }
        }
        if (!best) break;
        tmp.push_back(best);
        ck[best] = true;
        u = best;
    }

    if (tmp.size() > res.size())
        res = tmp;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0, u, v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
        arr[i] = i, sort(adj[i].begin(), adj[i].end(), cmp);
    sort(arr+1, arr+1+n, cmp);

    int bound = min(100000000/m, n);
    for (int i = 1; i <= bound; ++i)
        Try(arr[i]);

    printf("%d\n", (int)res.size());
    for (int i = 0; i < (int)res.size(); ++i)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}
