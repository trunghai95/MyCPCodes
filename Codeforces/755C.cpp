#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10000;
int n, v, p[MAXN+2], rk[MAXN+2], cnt;

int find(int x) {
    return (x == p[x] ? x : (p[x] = find(p[x])));
}

bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return false;

    if (rk[x] < rk[y]) swap(x, y);

    rk[x] += rk[y];
    p[y] = x;
    return true;
}

int main() {
    scanf("%d", &n);
    cnt = n;
    for (int u = 1; u <= n; ++u) {
        p[u] = u;
        rk[u] = 1;
    }

    for (int u = 1; u <= n; ++u) {
        scanf("%d", &v);
        if (join(u, v))
            --cnt;
    }

    printf("%d\n", cnt);
    return 0;
}
