#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int n, a[MAXN+2];
bool ck[MAXN+2];

int lcm(int x, int y) {
    return x / __gcd(x, y) * y;
}

int proc(int u) {
    int res = 0;
    while (!ck[u]) {
        ++res;
        ck[u] = true;
        u = a[u];
    }

    return res;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d", a+i), ck[a[i]] = true;

    for (int i = 1; i <= n; ++i) {
        if (!ck[i]) {
            printf("-1\n");
            return 0;
        }
    }
    memset(ck, 0, sizeof(ck));

    int res = 1;
    for (int i = 1; i <= n; ++i)
    if (!ck[i]) {
        int tmp = proc(i);
        if (tmp & 1) res = lcm(res, tmp);
        else res = lcm(res, tmp/2);
    }

    printf("%d\n", res);
    return 0;
}
