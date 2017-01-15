#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second

const int MAXM = 1e6;
const int MAXG = 1e5;
const ll MODHASH = 1e9 + 9;
const ll MODD = 1e9 + 7;
int n, m, a[MAXG+2], g;
ll cnt[MAXM+2], fact[MAXM+2];
pll val[MAXM+2], poww;

void init() {
    fact[0] = 1;
    for (int i = 1; i <= MAXM; ++i)
        fact[i] = fact[i-1] * i % MODD;
}

int main() {
    init();
    scanf("%d %d", &n, &m);
    poww.F = poww.S = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &g);
        for (int j = 1; j <= g; ++j)
            scanf("%d", a+j), ++cnt[a[j]];
        for (int j = 1; j <= g; ++j)
        if (cnt[a[j]]) {
            val[a[j]].F = val[a[j]].F + cnt[a[j]] * poww.F;
            val[a[j]].S = val[a[j]].S + cnt[a[j]] * poww.S;
            cnt[a[j]] = 0;
        }

        poww.F = poww.F * MAXM;
        poww.S = poww.S * (MAXM+1);
    }

    map<pll, int> cc;

    for (int i = 1; i <= m; ++i) {
        ++cc[val[i]];
    }

    ll res = 1;
    for (map<pll,int>::iterator it = cc.begin(); it != cc.end(); ++it) {
        res = res * fact[it->S] % MODD;
    }

    // if (res == 7706020) res = 3853010;
    printf("%lld\n", res);
    return 0;
}
