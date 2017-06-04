#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

const int MAXN = 500;
int test, n, m, a[MAXN+2][MAXN+2], mx, dist[MAXN+2][MAXN+2];

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

bool valid(int x, int y) {
    return x > 0 && y > 0 && x <= n && y <= m;
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d %d", &n, &m);

        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            scanf("%d", a[i]+j);
            mx = max(mx, a[i][j]);
        }

        memset(dist, -1, sizeof(dist));
        queue<pii> q;

        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        if (a[i][j] == mx) {
            q.push(pii(i, j));
            dist[i][j] = 0;
        }

        mx = 0;
        while (!q.empty()) {
            pii u = q.front(); q.pop();
            mx = max(mx, dist[u.F][u.S]);

            for (int d = 0; d < 8; ++d) {
                pii v(u.F + dx[d], u.S + dy[d]);
                if (valid(v.F, v.S) && dist[v.F][v.S] == -1) {
                    q.push(v);
                    dist[v.F][v.S] = dist[u.F][u.S] + 1;
                }
            }
        }

        printf("%d\n", mx);
    }
    return 0;
}
