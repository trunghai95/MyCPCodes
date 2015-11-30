#include <bits/stdc++.h>

using namespace std;

long long test, l, r;

int main()
{
    scanf("%lld", &test);
    while (test--)
    {
        scanf("%lld %lld", &l, &r);
        double res = 1.0/l - 1.0/(r+1);
        printf("%.12lf\n", res);
    }
}
