#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define x first
#define y second

int n;
pll p1, p2, p[3000];
ll r1, r2;

ll dis(pll a, pll b)
{
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

bool cmp(const pll& a, const pll& b)
{
    return dis(a, p1) < dis(b, p1);
}

int main()
{
    cin >> n >> p1.x >> p1.y >> p2.x >> p2.y;

    for (int i = 0; i < n; ++i)
        cin >> p[i].x >> p[i].y;

    sort(p, p+n, cmp);

    ll res = dis(p1, p[n-1]);
    for (int i = 0; i < n; ++i)
    {
        r1 = dis(p1, p[i]);
        r2 = 0;
        for (int j = i+1; j < n; ++j)
            r2 = max(r2, dis(p2, p[j]));

        res = min(res, r1+r2);
    }

    r2 = 0;
    for (int j = 0; j < n; ++j)
        r2 = max(r2, dis(p2, p[j]));
    res = min(res, r2);

    cout << res;
    return 0;
}
