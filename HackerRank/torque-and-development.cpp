#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100000;
int test, n, m, p[MAXN+2], rk[MAXN+2], cpn;
ll c1, c2, res;

int find(int x) {
    return (p[x] == x ? x : (p[x] = find(p[x])));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    --cpn;
    if (rk[x] < rk[y]) swap(x, y);
    rk[x] += rk[y];
    p[y] = x;
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d %d %lld %lld", &n, &m, &c1, &c2);
        cpn = n;
        for (int i = 1; i <= n; ++i)
            p[i] = i, rk[i] = 1;

        for (int i = 0, u, v; i < m; ++i) {
            scanf("%d %d", &u, &v);
            join(u, v);
        }

        res = 2e18;
        for (int i = cpn; i <= n; ++i) {
            int j = n - i;
            res = min(res, c1*i + c2*j);
        }

        printf("%lld\n", res);
    }
    return 0;
}
