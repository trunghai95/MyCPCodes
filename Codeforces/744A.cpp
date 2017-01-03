#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int n, m, k, rk[MAXN+2], p[MAXN+2], cpn;
int gov[MAXN+2];
bool isGov[MAXN+2];

int find(int x) {
    return (p[x] == x ? x : (p[x] = find(p[x])));
}

bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;

    if (rk[x] < rk[y]) swap(x, y);
    rk[x] += rk[y];
    p[y] = x;
    return true;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    cpn = n;

    for (int i = 1; i <= n; ++i)
        p[i] = i, rk[i] = 1;

    for (int i = 1; i <= k; ++i)
        scanf("%d", gov+i);

    for (int i = 0, u, v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        if (join(u, v))
            --cpn;
    }

    int mx = -1;
    for (int i = 1; i <= k; ++i) {
        int j = find(gov[i]);
        isGov[j] = true;
        if (mx == -1 || rk[j] > rk[mx])
            mx = j;
    }

    int res = 0;

    for (int i = 1; i <= n; ++i)
    if (!isGov[i] && p[i] == i) {
        res += rk[i];
    }

    res = res + rk[mx];
    res = res * (res - 1) / 2;
    for (int i = 1; i <= k; ++i) {
        int j = find(gov[i]);
        if (j == mx) continue;
        res += rk[j] * (rk[j] - 1) / 2;
    }

    res = max(0, res - m);

    printf("%d\n", res);
    return 0;
}
