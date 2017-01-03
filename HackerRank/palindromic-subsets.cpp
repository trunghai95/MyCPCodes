#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;
const int MAXN = 100000;
int it[MAXN*4+3][26], cnt[26], n, q, lazy[MAXN*4+3], cache[26];
int type, u, v, t;
char s[MAXN+3];
ll pow2[MAXN+3];

void init() {
    pow2[0] = 1;
    for (int i = 1; i <= MAXN; ++i)
        pow2[i] = pow2[i-1] * 2 % MODD;
}

void build_IT(int node, int l, int r) {
    if (l > r) return;
    if (l == r) {
        it[node][s[l]-'a'] = 1;
        return;
    }

    int lnode = node * 2;
    int rnode = node * 2 + 1;
    int m = (l + r) / 2;
    build_IT(lnode, l, m);
    build_IT(rnode, m+1, r);

    for (int i = 0; i < 26; ++i)
        it[node][i] = it[lnode][i] + it[rnode][i];
}

void shift(int* a, int t) {
    for (int i = 0; i < 26; ++i)
        cache[(i+t)%26] = a[i];
    memcpy(a, cache, sizeof(cache));
}

void update_IT(int node, int l, int r, int u, int v, int t) {
    int lnode = node * 2;
    int rnode = node * 2 + 1;
    int m = (l + r) / 2;
    if (lazy[node]) {
        shift(it[node], lazy[node]);
        if (l != r) {
            lazy[lnode] = (lazy[lnode] + lazy[node]) % 26;
            lazy[rnode] = (lazy[rnode] + lazy[node]) % 26;
        }
        lazy[node] = 0;
    }

    if (l > r || l > v || r < u) return;

    if (l >= u && r <= v) {
        shift(it[node], t);
        if (l != r) {
            lazy[lnode] = (lazy[lnode] + t) % 26;
            lazy[rnode] = (lazy[rnode] + t) % 26;
        }
        return;
    }

    update_IT(lnode, l, m, u, v, t);
    update_IT(rnode, m+1, r, u, v, t);

    for (int i = 0; i < 26; ++i)
        it[node][i] = it[lnode][i] + it[rnode][i];
}

void get_IT(int node, int l, int r, int u, int v) {
    if (l > r || l > v || r < u) return;
    
    int lnode = node * 2;
    int rnode = node * 2 + 1;
    int m = (l + r) / 2;
    if (lazy[node]) {
        shift(it[node], lazy[node]);
        if (l != r) {
            lazy[lnode] = (lazy[lnode] + lazy[node]) % 26;
            lazy[rnode] = (lazy[rnode] + lazy[node]) % 26;
        }
        lazy[node] = 0;
    }

    if (l >= u && r <= v) {
        for (int i = 0; i < 26; ++i)
            cnt[i] += it[node][i];
        return;
    }

    get_IT(lnode, l, m, u, v);
    get_IT(rnode, m+1, r, u, v);
}

int main() {
    init();
    scanf("%d %d %s", &n, &q, s);

    build_IT(1, 0, n-1);

    while (q --> 0) {
        scanf("%d %d %d", &type, &u, &v);

        if (type == 1) {
            scanf("%d", &t);
            t %= 26;
            update_IT(1, 0, n-1, u, v, t);
        } else {
            memset(cnt, 0, sizeof(cnt));
            get_IT(1, 0, n-1, u, v);
            ll sum = 1;
            int cc = 1;
            for (int i = 0; i < 26; ++i)
            if (cnt[i]) {
                sum = sum * pow2[cnt[i] - 1] % MODD, ++cc;
            }

            ll res = (sum * cc - 1 + MODD) % MODD;
            printf("%lld\n", res);
        }
    }
    return 0;
}
