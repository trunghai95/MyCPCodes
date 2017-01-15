#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define F first
#define S second

const int MAXN = 300;
int test, n, m, a[MAXN+2][MAXN+2];

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d %d", &n, &m);

        priority_queue<piii, vector<piii>, greater<piii> > heap;
        int res = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j)
                scanf("%d", a[i]+j);
            sort(a[i]+1, a[i]+1+m);
            heap.push(piii(a[i][1]+1, pii(i, 1)));

            piii u = heap.top();
            heap.pop();
            res += u.F;
            if (u.S.S < m) {
                int j = ++u.S.S;
                u.F = a[u.S.F][j] + (j*j - (j-1)*(j-1));
                heap.push(u);
            }
        }

        printf("Case #%d: %d\n", tt, res);
    }
    return 0;
}
