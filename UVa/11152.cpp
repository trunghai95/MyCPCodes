#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);
double a, b, c, S1, S2, S3, R, r, p;

int main() {
    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
        p = (a + b + c) / 2;
        S2 = sqrt(p*(p-a)*(p-b)*(p-c));
        r = S2 / p;
        R = a*b*c/(sqrt((a+b+c)*(a+b-c)*(a+c-b)*(b+c-a)));

        S1 = R*R*PI - S2;
        S2 = S2 - r*r*PI;
        S3 = r*r*PI;

        printf("%.4lf %.4lf %.4lf\n", S1, S2, S3);
    }
    return 0;
}
