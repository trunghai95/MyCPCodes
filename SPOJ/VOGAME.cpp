#include <bits/stdc++.h>

using namespace std;

int n, d, a[100010], test;

int main()
{
    scanf("%d", &test);
    while (test--)
    {
        scanf("%d %d", &n, &d);
        for (int i = 1; i <= d; ++i)
        {
            scanf("%d", a+i);
            a[i] = a[i] + a[i-1];
        }

        n = n % (d + 1) + 1;
        int cnt = a[d] + (a[d] & 1) + a[n - 1];
        if (cnt & 1)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
