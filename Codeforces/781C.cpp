#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int n, m, k;
vector<int> adj[MAXN+2], vec;
bool ck[MAXN+2];

void dfs(int u) {
    vec.push_back(u);
    ck[u] = true;

    for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if (!ck[v]) {
            dfs(v);
            vec.push_back(u);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0, u, v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    int kk = (vec.size() - 1) / k + 1;
    int i = 0;

    while (k --> 0) {
        if (i < (int)vec.size()) {
            int tmp = min(kk, (int)vec.size() - i);

            printf("%d ", tmp);
            while (tmp --> 0) {
                printf("%d ", vec[i]);
                ++i;
            }
            printf("\n");
        } else {
            printf("1 1\n");
        }
    }

    return 0;
}
