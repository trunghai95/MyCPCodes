#include <bits/stdc++.h>

using namespace std;

struct Person {
    int height;
    string sex, music, sport;
};

int test, n, n1, n2, pairU[510], pairV[510], dist[510];
Person pU[510], pV[510], tmp;
vector<int> adj[510];

bool bfs() {
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    int mx = -1;
    for (int u = 1; u <= n1; ++u)
    if (pairU[u] == -1)
        dist[u] = 0, q.push(u);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (mx != -1 && dist[u] >= mx) continue;

        for (int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i];

            if (pairV[v] == -1) mx = dist[u];
            else if (dist[pairV[v]] == -1) {
                q.push(pairV[v]);
                dist[pairV[v]] = dist[u] + 1;
            }
        }
    }

    return (mx != -1);
}

bool dfs(int u) {
    for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if (pairV[v] == -1 || (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v]))) {
            pairU[u] = v;
            pairV[v] = u;
            return true;
        }
    }

    dist[u] = -1;
    return false;
}

int maxMatching() {
    memset(pairU, -1, sizeof(pairU));
    memset(pairV, -1, sizeof(pairV));
    int res = 0;
    while (bfs()) {
        for (int u = 1; u <= n1; ++u) {
            if (pairU[u] == -1 && dfs(u))
                ++res;
        }
    }
    return res;
}

int main() {
    cin >> test;

    while (test --> 0) {
        cin >> n;
        n1 = n2 = 0;
        for (int tt = 0; tt < n; ++tt) {
            cin >> tmp.height >> tmp.sex >> tmp.music >> tmp.sport;
            if (tmp.sex == "F") {
                pU[++n1] = tmp;
                adj[n1].clear();
                for (int i = 1; i <= n2; ++i) {
                    if (abs(pV[i].height - tmp.height) <= 40
                        && pV[i].music == tmp.music
                        && pV[i].sport != tmp.sport) {
                        adj[n1].push_back(i);
                    }
                }
            } else {
                pV[++n2] = tmp;
                for (int i = 1; i <= n1; ++i) {
                    if (abs(pU[i].height - tmp.height) <= 40
                        && pU[i].music == tmp.music
                        && pU[i].sport != tmp.sport) {
                        adj[i].push_back(n2);
                    }
                }
            }
        }

        cout << n - maxMatching() << '\n';
    }
    return 0;
}