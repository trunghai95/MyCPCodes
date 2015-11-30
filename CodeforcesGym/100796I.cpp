#include <bits/stdc++.h>

using namespace std;

double r, R, h, H, res;

int main()
{
    scanf("%lf %lf %lf", &r, &R, &h);
    H = h + h*r/(R-r);
    double tmp = sin(atan(H/R));
    res = tmp*H*R/(H+tmp*R);
    res = min(res, h/2);
    printf("%.12lf", res);
    return 0;
}
