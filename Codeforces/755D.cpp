#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1000000;
int n, k, bit[MAXN+2], lst;
ll cur;

void update(int x) {
    while (x <= n) {
        ++bit[x];
        x += x&(-x);
    }
}

int get2(int x) {
    int res = 0;
    while (x) {
        res += bit[x];
        x -= x&(-x);
    }
    return res;
}

int get(int u, int v) {
    ++u, --v;
    if (u > n) u -= n;
    if (v < 1) v += n;

    if (u <= v) {
        return get2(v) - get2(u-1);
    } else {
        return get2(v) + get2(n) - get2(u-1);
    }
}

int main() {
    scanf("%d %d", &n, &k);
    cur = lst = 1;

    for (int i = 1; i <= n; ++i) {
        int nxt = lst + k;
        if (nxt > n) nxt -= n;

        int tmp = min(get(lst, nxt), get(nxt, lst));
        cur = cur + 1LL + tmp;

        printf("%lld ", cur);
        update(lst);
        update(nxt);
        lst = nxt;
    }
    printf("\n");
    return 0;
}
