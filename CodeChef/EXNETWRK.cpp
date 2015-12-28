#include <bits/stdc++.h>

using namespace std;

int n, m, test;

int main()
{
    scanf("%d", &test);

    while (test--)
    {
        scanf("%d %d", &n, &m);

        if (n == 1)
        {
            printf("-1 -1\n");
            continue;
        }

        if (n == 2)
        {
            printf("1 2\n");
            continue;
        }

        if (m == n)
        {
            for (int i = 0; i < n; ++i)
            {
                int j = (i + 1) % n;
                printf("%d %d\n", i + 1, j + 1);
            }
            continue;
        }

        if (m < n || n < 5)
        {
            printf("-1 -1\n");
            continue;
        }

        int c = m - n + 2;
        if (c > n - 2)
            printf("-1 -1\n");
        else
        {
            for (int i = 1; i < c; ++i)
                printf("1 %d\n%d 2\n", 2 + i, 2 + i);

            printf("1 %d\n", c + 2);
            for (int i = 2 + c; i < n; ++i)
                printf("%d %d\n", i, i + 1);
            printf("%d 2\n", n, 2);
        }
    }
    return 0;
}
