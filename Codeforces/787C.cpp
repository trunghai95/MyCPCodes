#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

const int MAXN = 7000;
int n, m[2], a[2][MAXN+2], res[2][MAXN+2], cnt[2][MAXN+2];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < 2; ++i) {
        scanf("%d", m+i);
        for (int j = 0; j < m[i]; ++j) {
            scanf("%d", a[i]+j);
        }
    }

    fill(res[0], res[0]+MAXN+2, -1);
    fill(res[1], res[1]+MAXN+2, -1);

    res[0][0] = 1;
    res[1][0] = 0;

    queue<pii> q;
    q.push(pii(0, 0));
    q.push(pii(1, 0));

    while (!q.empty()) {
        pii u = q.front();
        q.pop();

        if (res[u.F][u.S] != u.F) {
            for (int i = 0; i < m[1 - u.F]; ++i) {
                int step = a[1 - u.F][i];
                step = (u.S - step + n) % n;
                if (res[1 - u.F][step] != -1) {
                    continue;
                }
                res[1 - u.F][step] = 1 - u.F;
                q.push(pii(1 - u.F, step));
            }
        } else {
            for (int i = 0; i < m[1 - u.F]; ++i) {
                int step = a[1 - u.F][i];
                step = (u.S - step + n) % n;
                if (res[1 - u.F][step] != -1) {
                    continue;
                }
                if (++cnt[1 - u.F][step] == m[1 - u.F]) {
                    q.push(pii(1 - u.F, step));
                    res[1 - u.F][step] = u.F;
                }
            }
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j < n; ++j) {
            if (res[i][j] == i) {
                printf("Win ");
            } else if (res[i][j] == 1 - i) {
                printf("Lose ");
            } else {
                printf("Loop ");
            }
        }

        printf("\n");
    }
    return 0;
}
