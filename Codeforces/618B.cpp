#include <bits/stdc++.h>

using namespace std;

int n, a, res[60];

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
    {
        res[i] = 0;
        for (int j = 1; j <= n; ++j)
        {
            scanf("%d", &a);
            res[i] = max(res[i],a);
        }
    }

    for (int i = 1; i <= n; ++i)
    if (res[i] == n-1)
    {
        res[i] = n;
        break;
    }

    for (int i = 1; i <= n; ++i)
        printf("%d ", res[i]);
    return 0;
}
