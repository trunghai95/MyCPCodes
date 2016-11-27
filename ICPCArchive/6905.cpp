#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

struct Proposal {
    int b, e, p;

    bool operator<(const Proposal& other) const {
        if (this->b == other.b) {
            return this->e < other.e;
        }
        return this->b < other.b;
    }
};

const int MAXN = 10000;
const int MAX2N = MAXN*2;
int test, n;
pii bit[MAX2N+3], dp[MAXN+3];
Proposal a[MAXN+3], b[MAXN+3];
bool ck[MAXN+3];

pii get(int x) {
    pii res(0, 0);

    while (x > 0) {
        if (bit[x].F > res.F) {
            res = bit[x];
        }
        x -= x&(-x);
    }

    return res;
}

void update(int x, pii p) {
    while (x <= MAX2N) {
        if (bit[x].F < p.F) {
            bit[x] = p;
        }
        x += x&(-x);
    }
}

void compress() {
    vector<int> v;
    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        v.push_back(a[i].b);
        v.push_back(a[i].e);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < (int)v.size(); ++i) {
        if (!i || v[i] > v[i-1]) {
            mp[v[i]] = mp.size();
        }
    }

    for (int i = 1; i <= n; ++i) {
        a[i].b = mp[a[i].b];
        a[i].e = mp[a[i].e];
    }
}

int solve() {
    if (n == 0) return 0;
    memset(bit, 0, sizeof(bit));
    memset(ck, 0, sizeof(ck));

    for (int i = 1; i <= n; ++i) {
        pii p = get(a[i].b - 1);
        dp[i].F = p.F + a[i].p;
        dp[i].S = p.S;
        update(a[i].e, pii(dp[i].F, i));
    }

    int mxi = 1;
    for (int i = 2; i <= n; ++i) {
        if (dp[i].F > dp[mxi].F) {
            mxi = i;
        }
    }

    for (int i = mxi; i > 0; i = dp[i].S) {
        ck[i] = true;
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (!ck[i]) {
            b[++cnt] = a[i];
        }
    }

    memcpy(a, b, sizeof(a));
    n = cnt;
    return dp[mxi].F;
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d %d", &a[i].b, &a[i].e, &a[i].p);
        }
        compress();
        sort(a+1, a+1+n);

        int res = solve();
        res += solve();

        printf("%d\n", res);
    }
    return 0;
}
