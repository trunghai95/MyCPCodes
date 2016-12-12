#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);
double a, s1, s2, s3;

int main() {
    while (scanf("%lf", &a) != EOF) {
        double s = a*a*PI/4;
        double b = a * sin(PI/12) * 2;
        double h = a * cos(PI/12);
        s1 = s / 3 - h*b/2;
        s1 = s1*4 + b*b;

        s2 = s + s - a*a;
        s2 = s2 + s2 - s1*2;
        s3 = a*a - s1 - s2;
        printf("%.3lf %.3lf %.3lf\n", s1, s2, s3);
    }
    return 0;
}
