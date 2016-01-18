#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

const double PI = 3.14159265359;

int n;
ll x, y;
pii p, a[100010];

int main()
{
    ll l = 1000000000000000000, r = 1000000000000000000, k = 999999999, n = 1;
    while (n < l)
        n *= k;
    cout << n;
    return 0;
    scanf("%d %lld %lld", &n, &p.first, &p.second);

    double mn = 1e18, mx = 0;

    for (int i = 0; i < n; ++i)
    {
        scanf("%lld %lld", &a[i].first, &a[i].second);
        double d = (a[i].first - p.first)*(a[i].first - p.first) + (a[i].second - p.second)*(a[i].second - p.second);
        if (d < mn) mn = d;
        if (d > mx) mx = d;
    }

    for (int i = 0; i < n; ++i)
    {
        pii p1 = a[i];
        pii p2 = a[(i+1) % n];
        if (p1.first > p2.first) swap(p1, p2);
        else if (p1.first == p2.first && p1.second > p2.second) swap(p1,p2);

        double A, B, C;
        if (p1.first == p2.first)
            A = 1, B = 0;
        else
            B = 1, A = 1.0*B*(p2.second - p1.second)/(p1.first - p2.first);

        C = - A*p1.first - B*p1.second;

        double AA = -B, BB = A, CC = -(AA*p.first + BB*p.second);
        double xx, yy;

        if (A == 0)
        {
            yy = -C / B;
            xx = -CC / AA;
        }
        else if (B == 0)
        {
            xx = -C/A;
            yy = -CC/BB;
        }
        else
        {
            yy = (CC*A/AA - C) / (B - BB*A/AA);
            xx = (- C - B*yy) / A;
        }

        if (xx < p1.first || xx > p2.first || (p1.first == p2.first && (yy < p1.second || yy > p2.second)))
            continue;

        double d = (A*p.first + B*p.second + C)*(A*p.first + B*p.second + C) / (A*A + B*B);
        if (d < mn) mn = d;
    }

    double res = PI * (mx - mn);

    printf("%.12lf", res);

    return 0;
}
