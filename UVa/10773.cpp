#include <bits/stdc++.h>

using namespace std;

int t;
double d, u, v, p;

int main()
{
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cin >> d >> v >> u;
        if (u == 0 || v == 0 || u <= v)
            printf("Case %d: can't determine\n",i);
        else
            printf("Case %d: %.3lf\n",i,d/sqrt(u*u-v*v)-d/u);
    }
    return 0;
}
