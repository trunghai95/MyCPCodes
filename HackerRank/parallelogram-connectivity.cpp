#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

const int MAXN = 800;
int dx[] = { 1, -1, 0, 0, 1, -1 };
int dy[] = { 0, 0, 1, -1, -1, 1 };
int n, m, q, a1, b1, a2, b2;
char s[MAXN+2][MAXN+2];
bool ck[MAXN+2][MAXN+2];

bool valid(pii u) {
    return (u.F >= a1 && u.F <= a2 && u.S >= b1 && u.S <= b2);
}

void bfs(pii x) {
    queue<pii> q;
    ck[x.F][x.S] = true;
    q.push(x);

    while (!q.empty()) {
        pii u = q.front();
        q.pop();

        for (int i = 0; i < 6; ++i) {
            pii v(u.F + dx[i], u.S + dy[i]);
            if (valid(v) && !ck[v.F][v.S] && s[v.F][v.S] == s[u.F][u.S]) {
                ck[v.F][v.S] = true;
                q.push(v);
            }
        }
    }
}

int solve() {
    int res = 0;
    for (int i = a1; i <= a2; ++i)
    for (int j = b1; j <= b2; ++j)
    if (!ck[i][j]) {
        bfs(pii(i, j));
        ++res;
    }

    for (int i = a1; i <= a2; ++i)
        memset(ck[i]+b1, 0, b2 - b1 + 1);

    return res;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        scanf("%s", s[i] + 1);
    }

    scanf("%d", &q);

    while (q --> 0) {
        scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
        printf("%d\n", solve());
    }
    return 0;
}
