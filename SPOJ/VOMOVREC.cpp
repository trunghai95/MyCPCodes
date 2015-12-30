#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100000;

int n;
ll X1[MAXN], Y1[MAXN], X2[MAXN], Y2[MAXN];

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld %lld %lld %lld", X1+i, Y1+i, X2+i, Y2+i);

    ll lef = 0, rig = 2e9;

    while (lef < rig)
    {
        ll mid = ((lef + rig) >> 1);
        ll xmax, xmin, ymax, ymin;
        xmax = ymax = 1e12;
        xmin = ymin = -1e12;

        for (int i = 0; i < n; ++i)
        {
            xmin = max(xmin, X1[i] - mid);
            xmax = min(xmax, X2[i] + mid);
            ymin = max(ymin, Y1[i] - mid);
            ymax = min(ymax, Y2[i] + mid);
        }

        if (xmin < xmax && ymin < ymax)
            rig = mid;
        else lef = mid + 1;
    }

    printf("%lld", lef);

    return 0;
}
