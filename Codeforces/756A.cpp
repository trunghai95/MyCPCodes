#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
int n, p[MAXN+2], b[MAXN+2], cnt1, cpn;
bool ck[MAXN+2];

void proc(int u) {
    while (!ck[u]) {
        ck[u] = true;
        u = p[u];
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d", p+i);

    for (int i = 1; i <= n; ++i)
        scanf("%d", b+i), cnt1 += (b[i] == 1);

    for (int i = 1; i <= n; ++i)
    if (!ck[i]) {
        proc(i);
        ++cpn;
    }

    int res = cpn;
    if (cpn == 1) res = 0;
    if (!(cnt1&1)) {
        ++res;
    }

    printf("%d\n", res);
    return 0;
}
