#include <bits/stdc++.h>

using namespace std;

int n;
double p[111], res, etc, tmp;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lf", p+i);
    sort(p,p+n);
    res = p[n-1];
    etc = 1.0 - p[n-1];

    for (int i = 0; i < n-1; ++i)
    {
        tmp = res*(1.0 - p[i]) + etc*p[i];
        if (tmp < res) break;
        res = tmp;
        etc *= 1.0 - p[i];
    }

    printf("%.12lf", res);
    return 0;
}
