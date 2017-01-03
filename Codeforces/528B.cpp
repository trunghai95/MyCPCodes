#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
const int INF = 2e9;
vector<int> step;
int dist[MAXN+2], pre[MAXN+2], n;

void init() {
    int tmp = 1;
    for (int i = 1; i <= 6; ++i) {
        int sz = step.size();
        step.push_back(tmp);
        for (int i = 0; i < sz; ++i)
            step.push_back(tmp + step[i]);
        tmp *= 10;
    }
    step.push_back(1000000);
}

int main() {
    init();
    scanf("%d", &n);

    queue<int> q;
    fill(dist, dist + n + 1, INF);
    q.push(0);
    dist[0] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == n) break;

        for (int i = 0; i < (int)step.size(); ++i) {
            int v = u + step[i];
            if (v > n) break;
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                pre[v] = u;
                q.push(v);
            }
        }
    }

    printf("%d\n", dist[n]);
    while (n > 0) {
        printf("%d ", n - pre[n]);
        n = pre[n];
    }
    printf("\n");
    return 0;
}
