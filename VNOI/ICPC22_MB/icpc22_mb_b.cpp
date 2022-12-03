#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MAXM = 1000006;
const int MAXN = 15;
int n, dist[MAXM];
ll m, s, t, a[MAXN], b[MAXN];
queue<int> q;

int main() {
    scanf("%lld %d %lld", &m, &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &a[i], &b[i]);
    }

    memset(dist, -1, sizeof(dist));
    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        s = q.front();
        q.pop();
        if (s == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            t = (s*a[i] + b[i]) % m;
            if (dist[t] >= 0) {
                continue;
            }
            dist[t] = dist[s] + 1;
            q.push(t);
        }
    }
    printf("%d\n", dist[0]);
    return 0;
}