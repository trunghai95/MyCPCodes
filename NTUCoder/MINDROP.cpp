#include <bits/stdc++.h>

using namespace std;

int n, a[100000], res;

int main()
{
    scanf("%d %d", &n, a);
    int cnt = 1;

    for (int i = 1; i < n; ++i)
    {
        scanf("%d", a+i);
        if (a[i] != a[i-1])
        {
            res = max(cnt, res);
            cnt = 1;
        }
        else ++cnt;
    }

    res = max(cnt, res);

    printf("%d", n - res);
    return 0;
}
