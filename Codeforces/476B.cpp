#include <bits/stdc++.h>

using namespace std;

int n, sum1, sum2, t, h;
char s1[20], s2[20];
double res;

int choose(int n, int k)
{
    if (k == n || k == 0) return 1;
    return choose(n-1,k) + choose(n-1,k-1);
}

int main()
{
    scanf("%s %s", s1, s2);
    sum1 = sum2 = t = 0;
    n = strlen(s1);
    for (int i = 0; i < n; ++i)
    {
        switch(s1[i])
        {
            case '+': ++sum1; break;
            case '-': --sum1; break;
        }
        switch(s2[i])
        {
            case '+': ++sum2; break;
            case '-': --sum2; break;
            case '?': ++t; break;
        }
    }
    if (t == 0)
        res = (sum1 == sum2);
    else
    {
        h = sum1 - sum2;
        h = (t-h)/2;
        if (h >= 0 && h <= t)
            res = 1.0*choose(t,h)/pow(2.0, 1.0*t);
        else res = 0.0;
    }
    printf("%.12lf", res);
    return 0;
}
