#include <bits/stdc++.h>

using namespace std;

int n, a[100000];


int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a+i);

    sort(a, a+n);
    int res;
    for (res = n - 1; res >= 0; --res)
    {
        if (a[res] <= res)
            break;
    }

    printf("%d", res + 1);
    return 0;
}
