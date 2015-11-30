#include <bits/stdc++.h>

using namespace std;

char s[51];
double p, res;
int n;

int main()
{
    scanf("%s %lf", s, &p);
    n = strlen(s);
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '?')
            res += p;
        else
            res += 1.0*(s[i] - '0');
    }
    res /= 1.0*n;
    printf("%.5lf", res);
    return 0;
}
