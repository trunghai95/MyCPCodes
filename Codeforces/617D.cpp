#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

#define x first
#define y second

pii p[3];

bool cmpy(pii a, pii b) { return a.y < b.y; }

int main()
{
    for (int i = 0; i < 3; ++i)
        cin >> p[i].x >> p[i].y;

    sort(p, p+3);
    if ((p[0].x == p[1].x && p[0].x == p[2].x) || (p[0].y == p[1].y && p[0].y == p[2].y))
    {
        cout << 1;
        return 0;
    }

    if ((p[0].x == p[1].x && (p[2].y <= min(p[0].y, p[1].y) || p[2].y >= max(p[0].y, p[1].y)))
        || (p[2].x == p[1].x && (p[0].y <= min(p[2].y, p[1].y) || p[0].y >= max(p[2].y, p[1].y))))
    {
        cout << 2;
        return 0;
    }

    sort(p, p+3, cmpy);
    if ((p[0].y == p[1].y && (p[2].x <= min(p[0].x, p[1].x) || p[2].x >= max(p[0].x, p[1].x)))
        || (p[2].y == p[1].y && (p[0].x <= min(p[2].x, p[1].x) || p[0].x >= max(p[2].x, p[1].x))))
    {
        cout << 2;
        return 0;
    }

    cout << 3;
    return 0;
}
