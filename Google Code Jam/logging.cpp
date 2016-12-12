#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second

int test, n, m;
pll p[3001];
int v[3000];
double ang[3001];

bool cmp(const int &x, const int &y) {
    return ang[x] < ang[y];
}

bool valid(const pll &a, const pll &b, const pll &c) {
    return (b.F - a.F) * (c.S - a.S) - (b.S - a.S) * (c.F - a.F) > 0;
}

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        printf("Case #%d:\n", tt);
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld %lld", &p[i].F, &p[i].S);
        }
        m = n-1;

        for (int i = 1; i <= n; ++i) {
            int res = n-1;
            for (int j = 1; j < i; ++j)
                v[j] = j, ang[j] = atan2(p[j].S - p[i].S, p[j].F - p[i].F);
            for (int j = i+1; j <= n; ++j)
                v[j-1] = j, ang[j] = atan2(p[j].S - p[i].S, p[j].F - p[i].F);
                
            sort(v+1, v+1+m, cmp);

            int p1 = 1, p2 = 1;
            while (p1 <= m) {
                if (++p2 > m) p2 = 1;
                while (p1 != p2 && valid(p[i], p[v[p1]], p[v[p2]])) {
                    if (++p2 > m) p2 = 1;
                }

                if (--p2 <= 0) p2 = m;
                if (p1 <= p2) {
                    res = min(res, p2 - p1);
                } else {
                    res = min(res, p2 + m - p1);
                }

                if (p1 == p2) {
                    ++p2;
                }
                ++p1;
            }

            printf("%d\n", res);
        }
    }
    return 0;
}
