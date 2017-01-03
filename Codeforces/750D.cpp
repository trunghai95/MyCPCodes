#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,pii> pii2;
#define F first
#define S second

const int MAXD = 320;
int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
int n, a[32];
bool ck[MAXD+2][MAXD+2][9][6], ck2[MAXD+2][MAXD+2][8][32];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
    }

    --a[1];

    queue<pii2> q;
    q.push(pii2(pii(MAXD/2, MAXD/2), pii(0,1)));
    ck2[MAXD/2][MAXD/2][0][1] = true;
    ck[MAXD/2][MAXD/2][8][1] = true;

    while (!q.empty()) {
        pii2 u = q.front();
        q.pop();

        // cout << u.F.F << ' ' << u.F.S << ' ' << u.S.F << ' ' << u.S.S << '\n';

        if (ck[u.F.F][u.F.S][u.S.F][a[u.S.S]]) {
            u.F.F += dx[u.S.F]*(a[u.S.S]);
            u.F.S += dy[u.S.F]*(a[u.S.S]);
        } else {
            ck[u.F.F][u.F.S][u.S.F][a[u.S.S]] = true;
            for (int i = 0; i < a[u.S.S]; ++i) {
                u.F.F += dx[u.S.F];
                u.F.S += dy[u.S.F];
                ck[u.F.F][u.F.S][8][1] = true;
                // cout << u.F.F << ' ' << u.F.S << '\n';
            }
        }

        if (u.S.S == n) continue;

        int tmp = (u.S.F + 1) % 8;
        ++u.S.S;
        if (!ck2[u.F.F][u.F.S][tmp][u.S.S]) {
            ck2[u.F.F][u.F.S][tmp][u.S.S] = true;
            q.push(pii2(u.F, pii(tmp, u.S.S)));
        }

        tmp = (u.S.F + 7) % 8;
        if (!ck2[u.F.F][u.F.S][tmp][u.S.S]) {
            ck2[u.F.F][u.F.S][tmp][u.S.S] = true;
            q.push(pii2(u.F, pii(tmp, u.S.S)));
        }
    }

    int res = 0;
    for (int x = 0; x <= MAXD; ++x)
    for (int y = 0; y <= MAXD; ++y) {
        bool f = false;
        for (int i = 0; i < 9 && !f; ++i)
        for (int j = 0; j < 6 && !f; ++j)
        if (ck[x][y][i][j])
            f = true;
        if (f) ++res;
    }

    printf("%d\n", res);

    return 0;
}
