#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef pair<ld, int> pdi;
const ld PI = acos(-1.0);

pdi angle[100001];
int x, y, n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x >> y;
        angle[i].second = i;

        if (y >= 0 && x > 0)
            angle[i].first = atan(1.0*y/x);
        else if (x <= 0 && y > 0)
            angle[i].first = atan(-1.0*x/y) + PI / 2.0;
        else if (y <= 0 && x < 0)
            angle[i].first = atan(1.0*y/x) + PI;
        else angle[i].first = atan(-1.0*x/y) + 1.5*PI;
    }
    sort(angle+1, angle+1+n);
    ld mn = abs(angle[1].first - angle[n].first);
    if (mn > PI) mn = PI*2.0 - mn;
    int mxp1 = 1, mxp2 = n;

    for (int i = 1; i < n; ++i)
    {
        ld tmp = abs(angle[i].first - angle[i+1].first);
        if (tmp > PI) tmp = PI*2.0 - tmp;
        if (tmp < mn)
        {
            mn = tmp;
            mxp1 = i;
            mxp2 = i + 1;
        }
    }
    cout << angle[mxp1].second << ' ' << angle[mxp2].second;
    return 0;
}
