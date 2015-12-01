#include <bits/stdc++.h>

using namespace std;

int test, n;

int main()
{
    scanf("%d", &test);

    while (test--)
    {
        int x;
        scanf("%d %d", &n, &x);
        int mx = x, sum = x, mxp = 1;

        for (int i = 2; i <= n; ++i)
        {
            scanf("%d", &x);
            sum += x;
            if (x == mx)
                mxp = 0;
            else if (x > mx)
                mx = x, mxp = i;
        }

        if (!mxp)
            printf("no winner\n");
        else if ((mx << 1) > sum)
            printf("majority winner %d\n", mxp);
        else printf("minority winner %d\n", mxp);
    }
    return 0;
}
