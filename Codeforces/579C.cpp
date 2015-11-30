#include <bits/stdc++.h>

using namespace std;

int a, b;
double x, res;

int main()
{
    //cin >> a >> b;
    scanf("%d %d", &a, &b);
    res = 2e11 + 5;

    int i = (a+b)/b;
    if (i&1) --i;
    if (i) res = 1.0*(a+b)/i;

    i = (a-b)/b;
    if (i&1) --i;
    if (i) res = min(res, 1.0*(a-b)/i);

    if (res > 2e11)
        printf("-1");
    else
        printf("%.12lf", res);
    return 0;
}
