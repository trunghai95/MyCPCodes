#include <bits/stdc++.h>

using namespace std;

const double EPS = 0.0001;
const double PI = 3.141592654;
double h, r, d1, d2, h1, h2, d, n, mCube, hMax, vCube, v, hc, hInc, hInc2, m1, m2;

int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &h, &r, &d1, &h1, &d2, &h2, &d, &n);
    if (abs(h1+h2-h) < EPS)
    {
        printf("%.3lf", h);
        return 0;
    }
    vCube = n*n*n;
    mCube = vCube*d;
    hMax = vCube/(PI*r*r);
    hc = min(n*d/d2,n);
    v = hc*n*n;
    hInc = v/(PI*r*r);

    if (h2 + hInc > n)
    {
        printf("%.3lf", min(h1+h2+hInc,h));
        return 0;
    }

    hInc2 = h2*n*n/(PI*r*r-n*n);
    m2 = PI*r*r*hInc2*d2;
    hInc = min((mCube - m2)/(d1*n*n),n-hInc2);

    if (h1+h2+hInc+hInc2 > n)
    {
        printf("%.3lf", min(h1+h2+hInc+hInc2,h));
        return 0;
    }

    hInc = h1*n*n/(PI*r*r-n*n);
    printf("%.3lf", min(h1+h2+hInc+hInc2,h));

    return 0;
}
