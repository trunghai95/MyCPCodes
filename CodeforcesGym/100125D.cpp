#include <bits/stdc++.h>

using namespace std;

const double EPS = 0.00000001;
int x, y, d;
double xa, ya, da, la, l;

int main()
{
    freopen("deepest.in", "r", stdin);
    freopen("deepest.out", "w", stdout);
    scanf("%d %d %d", &x, &y, &d);
    l = sqrt(1.0*x*x + 1.0*y*y);
    da = (1.0*d - l)/2.0;
    if (abs(da) < EPS)
    {
        printf("Single staircase");
        return 0;
    }
    if (da < 0)
    {
        printf("Impossible");
        return 0;
    }
    la = l + da;
    xa = la/l*x;
    ya = la/l*y;
    printf("%.10lf %.10lf %.10lf", xa, ya, da);
    return 0;
}
