#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
int test, n, m, h[MAXN][MAXN];
bool mc[MAXN], mr[MAXN];

int solve() {
    scanf("%d %d", &n, &m);
    memset(mc, 0, sizeof(mc));
    memset(mr, 0, sizeof(mr));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &h[i][j]);
            if (i > 0 && h[i][j] != h[i-1][j]) {
                mc[j] = true;
            }
            if (j > 0 && h[i][j] != h[i][j-1]) {
                mr[i] = true;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!mr[i] && !mc[j]) {
                res++;
            }
        }
    }
    return res;
}

int main() {
    scanf("%d", &test);
    while (test --> 0) {
        printf("%d\n", solve());
    }
    return 0;
}