#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
int n, root, res[MAXN+2], cnt[MAXN+2], rr = -1;
vector<int> adj[MAXN+2];
bool ck[MAXN+2];
set<int> s[MAXN+2];

int main() {
    scanf("%d", &n);

    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if ((int)adj[i].size() > 2) {
            root = i;
            break;
        }
    }

    if (root == 0) {
        --n;
        while (!(n&1)) {
            n >>= 1;
        }

        printf("%d\n", n);
        return 0;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() == 1) {
            q.push(i);
            ck[i] = true;
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();

        int uu = 0;
        for (int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i];
            if (!ck[v]) {
                uu = v;
                break;
            }
        }

        ++cnt[uu];
        s[uu].insert(res[u] + 1);
        if (cnt[uu] + 1 == (int)adj[uu].size()) {
            if (s[uu].size() == 1) {
                res[uu] = *(s[uu].begin());
                ck[uu] = true;
                q.push(uu);
            }
        } else if (cnt[uu] >= (int)adj[uu].size()) {
            if (s[uu].size() == 2) {
                set<int>::iterator it = s[uu].begin();
                rr = *it;
                ++it;
                rr += *it;
            }
            break;
        }
    }

    if (rr == -1) {
        bool f = true;
        for (int i = 1; i <= n; ++i) {
            if (!ck[i]) {
                f = false;
                break;
            }
        }

        if (!f) {
            printf("-1\n");
            return 0;
        }

        sort(res+1, res+1+n);
        rr = res[n] + res[n-1] + 1;
    }

    while (!(rr&1)) {
        rr >>= 1;
    }

    printf("%d\n", rr);
    return 0;
}
