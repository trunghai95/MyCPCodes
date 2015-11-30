#include <bits/stdc++.h>

using namespace std;

int n, m;
double res;

int main()
{
    scanf("%d %d", &n, &m);
    res = 1.0/n + 1.0*(n-1)/n*(m-1)*1.0/(n*m-1);
    if (n == 1 && m == 1) res = 1;
    printf("%.12lf", res);
    return 0;
}
