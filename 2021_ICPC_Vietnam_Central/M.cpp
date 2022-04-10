#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAXN = 100005;
const ll MOD = 1000000007;
ll fact[MAXN];

void calcFact() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i-1] * (ll)i % MOD;
    }
}

int n, m, p[MAXN], x, y, cnt[MAXN];

int find(int x) {
    if (p[x] == x) {
        return x;
    }
    return p[x] = find(p[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        p[y] = x;
    }
}

int main() {
    calcFact();
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    while (m --> 0) {
        scanf("%d %d", &x, &y);
        join(x, y);
    }

    ll res = 0;
    
    for (int i = 0; i < n; i++) {
        cnt[find(i)]++;
    }

    for (int i = 0; i < n; i++) {
        if (cnt[i] > 2) {
            res = (res + fact[cnt[i]]) % MOD;
        }
    }

    printf("%lld\n", res);

    return 0;
}