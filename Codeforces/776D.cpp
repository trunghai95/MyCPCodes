#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, m, r[MAXN+2], sw[MAXN+2][2], state[MAXN+2];
vector<int> li[MAXN+2];

bool Try(int p, int s) {
    queue<int> q;
    vector<int> vec;
    state[p] = s;
    vec.push_back(p);
    q.push(p);
    bool ok = true;

    while (ok && !q.empty()) {
        int u = q.front(); q.pop();

        for (int i = 0; i < (int)li[u].size(); ++i) {
            int x = li[u][i], v;
            if (u == sw[x][0]) {
                v = sw[x][1];
            } else {
                v = sw[x][0];
            }

            if (!state[v]) {
                if (r[x]) {
                    state[v] = state[u];
                } else {
                    state[v] = -state[u];
                }

                q.push(v);
                vec.push_back(v);
            } else if (state[v] == state[u]) {
                if (!r[x]) {
                    ok = false;
                    break;
                }
            } else {
                if (r[x]) {
                    ok = false;
                    break;
                }
            }
        }
    }

    if (!ok) {
        for (int i = 0; i < (int)vec.size(); ++i) {
            state[vec[i]] = 0;
        }

        return false;
    }

    return true;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", r+i);
    }

    for (int i = 1, k; i <= m; ++i) {
        scanf("%d", &k);

        for (int j = 1, x; j <= k; ++j) {
            scanf("%d", &x);
            li[i].push_back(x);
            if (sw[x][0]) {
                sw[x][1] = i;
            } else {
                sw[x][0] = i;
            }
        }
    }

    for (int i = 1; i <= m; ++i)
    if (!state[i]) {
        if (!Try(i, -1) && !Try(i, 1)) {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");
    return 0;
}
