#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define x first
#define y second

int n, res[3], i;
pll p[100010];

ll gcd(ll x, ll y)
{
    if (!x || !y) return x | y;
    return gcd(y, x%y);
}

bool pointOnLine(pll a, pll b, pll c)
{
    ll x1 = b.x - a.x, y1 = b.y - a.y;
    ll x2 = b.x - c.x, y2 = b.y - c.y;

    if (x1 == 0 || x2 == 0)
    {
        if (x1 == x2)
            return true;
        return false;
    }

    if (y1 == 0 || y2 == 0)
    {
        if (y1 == y2)
            return true;
        return false;
    }

    if (x1 < 0) x1 = -x1, y1 = -y1;
    if (x2 < 0) x2 = -x2, y2 = -y2;
    ll g = gcd(abs(x1), abs(y1));
    x1 /= g, y1 /= g;
    g = gcd(abs(x2), abs(y2));
    x2 /= g, y2 /= g;

    return (x1 == x2 && y1 == y2);
}

bool pointOnSeg(pll a, pll b, pll c)
{
    ll x1 = b.x - a.x, y1 = b.y - a.y;
    ll x2 = b.x - c.x, y2 = b.y - c.y;

    if (x1 == 0 || x2 == 0)
    {
        if (x1 == x2 && (a.y - b.y)*(c.y - b.y) > 0 && (a.y - c.y)*(b.y - c.y) > 0)
            return true;
        return false;
    }

    if (y1 == 0 || y2 == 0)
    {
        if (y1 == y2 && (a.x - b.x)*(c.x - b.x) > 0 && (a.x - c.x)*(b.x - c.x) > 0)
            return true;
        return false;
    }

    if (x1 < 0) x1 = -x1, y1 = -y1;
    if (x2 < 0) x2 = -x2, y2 = -y2;
    ll g = gcd(abs(x1), abs(y1));
    x1 /= g, y1 /= g;
    g = gcd(abs(x2), abs(y2));
    x2 /= g, y2 /= g;

    if (x1 == x2 && y1 == y2)
        return ((a.y - b.y)*(c.y - b.y) > 0 && (a.y - c.y)*(b.y - c.y) > 0);
    return false;
}

ll sign(pll a, pll b, pll c)
{
    return (a.x - c.x)*(b.y - c.y) - (b.x - c.x)*(a.y - c.y);
}

bool pointInTriangle(pll pt, pll a, pll b, pll c)
{
    bool b1 = (sign(pt, a, b) < 0), b2 = (sign(pt, b, c) < 0), b3 = (sign(pt, c, a) < 0);
    return ((b1 == b2) && (b2 == b3));
}

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);

    for (i = 0; i < n; ++i)
        scanf("%lld %lld", &p[i].x, &p[i].y);

    res[0] = 0, res[1] = 1;
    i = 2;

    while (i < n)
    {
        if (pointOnLine(p[i], p[res[0]], p[res[1]]))
        {
            if (pointOnSeg(p[i], p[res[0]], p[res[1]]))
                res[1] = i;
        }
        else
        {
            res[2] = i++;
            break;
        }
        ++i;
    }

    while (i < n)
    {
        if (pointOnSeg(p[i], p[res[0]], p[res[1]]))
            res[1] = i;
        else if (pointOnSeg(p[i], p[res[1]], p[res[2]]))
            res[2] = i;
        else if (pointOnSeg(p[i], p[res[2]], p[res[0]]))
            res[0] = i;
        else if (pointInTriangle(p[i], p[res[0]], p[res[1]], p[res[2]]))
            res[2] = i;
        ++i;
    }

    printf("%d %d %d", res[0]+ 1, res[1] + 1, res[2] + 1);
    return 0;
}
