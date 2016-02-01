#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

int n, p, x, y;
ld prob[100010];

int main()
{
    scanf("%d %d", &n, &p);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &x, &y);
        int cnt = y/p - (x-1)/p;
        prob[i] = (ld)1.0 - (ld)cnt / (y - x + 1);
    }

    ld res = 0;

    for (int i = 0; i < n; ++i)
    {
        int j = (i + 1) % n;
        res += ((ld)1.0 - prob[i]*prob[j])*2000;
    }

    printf("%.9lf", (double)res);
    return 0;
}
