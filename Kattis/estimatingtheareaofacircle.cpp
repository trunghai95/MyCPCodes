#include <bits/stdc++.h>

using namespace std;

double r;
int c, m;

int main()
{
    ios_base::sync_with_stdio(0);
    while (1)
    {
        scanf("%lf %d %d", &r, &m, &c);

        if (!m && !c)
            return 0;

        printf("%.9lf %.9lf\n", r*r*3.141592654, 4.0*c/m*r*r);
    }
    return 0;
}
