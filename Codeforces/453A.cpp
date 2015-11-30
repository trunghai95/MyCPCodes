#include <bits/stdc++.h>

using namespace std;

int n, m;
double p, res;

int main()
{
    scanf("%d %d", &m, &n);
    res = 0;
    for (int i = 1; i <= m; ++i)
    {
        p = pow(1.0*i/m,n) - pow(1.0*(i-1)/m,n);
        res += p*i;
    }
    printf("%.12lf", res);
    return 0;
}
