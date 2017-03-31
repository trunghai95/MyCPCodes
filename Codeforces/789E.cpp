#include <bits/stdc++.h>

using namespace std;

int n, m, a, dist[3000];
bool ck[3000];
vector<int> v;

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        a = a - m;
        ck[a + 1000] = true;
    }

    for (int i = -1000; i <= 1000; ++i)
    if (ck[i + 1000]) {
        v.push_back(i);
    }

    queue<int> q;
    dist[1000] = 1;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (ck[u + 1000]) {
            printf("%d\n", dist[u + 1000]);
            return 0;
        }

        for (int i = 0; i < (int)v.size(); ++i) {
            int t = u - v[i];

            if (abs(t) <= 1000 && dist[t + 1000] == 0) {
                q.push(t);
                dist[t + 1000] = dist[u + 1000] + 1;
            }
        }
    }

    printf("-1\n");

    return 0;
}
