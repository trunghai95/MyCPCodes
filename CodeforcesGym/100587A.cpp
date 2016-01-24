#include <bits/stdc++.h>

using namespace std;

int top, bot, l, r, test, n, x, a[50001];

int main()
{
    //freopen("D:\\lazy.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt)
    {
        scanf("%d", &n);

        for (int i = 1; i <= n; ++i)
            scanf("%d", a+i);

        bool f1 = true, f2 = true;
        l = 2, r = n;
        top = bot = a[1];

        while (f1 && l <= r)
        {
            if (a[l] == bot + 1)
                bot = a[l++];
            else if (a[l] == top - 1)
                top = a[l++];
            else if (a[r] == bot + 1)
                bot = a[r--];
            else if (a[r] == top - 1)
                top = a[r--];
            else
                f1 = false;
        }

        l = 1, r = n-1;
        top = bot = a[n];

        while (f2 && l <= r)
        {
            if (a[l] == bot + 1)
                bot = a[l++];
            else if (a[l] == top - 1)
                top = a[l++];
            else if (a[r] == bot + 1)
                bot = a[r--];
            else if (a[r] == top - 1)
                top = a[r--];
            else
                f2 = false;
        }

        printf("Case #%d: ", tt);
        if (f1 || f2)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
