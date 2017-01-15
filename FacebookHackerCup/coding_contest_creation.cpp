#include <bits/stdc++.h>

using namespace std;

int test, n, d[100010];

int main()
{
    freopen("coding_contest_creation.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt)
    {
        scanf("%d", &n);

        for (int i = 1; i <= n; ++i)
            scanf("%d", d+i);

        int res = 0, i = 1, p = 0;

        while (i <= n)
        {
            if (i == n || p == 3 || d[i+1] <= d[i] || d[i+1] - d[i] > 30)
            {
                res += 3 - p;
                ++i;
                p = 0;
            }
            else if (d[i+1] - d[i] <= 10)
            {
                ++i;
                ++p;
            }
            else if (d[i+1] - d[i] <= 20)
            {
                ++res;
                ++i;
                if (p == 2)
                    p = 0;
                else
                    p += 2;
            }
            else // 20 < d[i+1] - d[i] <= 30
            {
                if (p == 0)
                {
                    res += 2;
                    p = 3;
                    ++i;
                }
                else
                {
                    res += 3 - p;
                    ++i;
                    p = 0;
                }
            }
        }

        printf("Case #%d: %d\n", tt, res);
    }
    return 0;
}
