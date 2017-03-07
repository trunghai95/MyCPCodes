#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
const int INF = 2e8;
int n, m, k, lef, rig, pp[MAXN+2];

int main() {
    scanf("%d %d", &n, &m);

    vector<vector<int> > a(n+1, vector<int>(m+1, 0));
    vector<vector<int> > p(n+1, vector<int>(m+1, 0));
    fill(pp+1, pp+1+n, INF);

    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
        scanf("%d", &a[i][j]);
    }

    for (int j = 1; j <= m; ++j) {
        p[1][j] = 1;
        for (int i = 2; i <= n; ++i) {
            if (a[i][j] >= a[i-1][j]) {
                p[i][j] = p[i-1][j];
            } else {
                p[i][j] = i;
            }
        }

        for (int i = 1; i <= n; ++i)
            pp[i] = min(pp[i], p[i][j]);
    }

    for (int i = n-1; i >= 1; --i) {
        pp[i] = min(pp[i], pp[i+1]);
    }

    scanf("%d", &k);
    while (k --> 0) {
        scanf("%d %d", &lef, &rig);
        if (pp[rig] <= lef) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
