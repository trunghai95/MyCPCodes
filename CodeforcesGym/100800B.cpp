#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592654
int n;
double g, d[4], theta[4], v[4], a[4];

double gpt(double a, double b, double c)
{
    double delta = b*b - 4*a*c;
    return (-b + sqrt(delta)) / (2.0*a);
}

int main()
{
    scanf("%d %lf", &n, &g);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf %lf", d+i, theta+i);
        theta[i] = theta[i] / 180.0 * PI;
        a[i] = g * cos(theta[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        double v0 = 0;
        for (int j = i; j < n; ++j)
        {
            double t = gpt(a[j] / 2.0, v0, -d[j]);
            v0 += a[j]*t;
        }
        printf("%lf\n", v0);
    }
    return 0;
}
