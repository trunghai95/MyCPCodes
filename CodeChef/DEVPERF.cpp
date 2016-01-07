#include <bits/stdc++.h>

using namespace std;

char s[1010][1010];
int n, m, test;

int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%d", &test);

    while (test--)
    {
        scanf("%d %d", &n, &m);
        int xmax, xmin, ymax, ymin;
        xmax = ymax = -1000000;
        xmin = ymin = 1000000;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", s[i] + 1);
            for (int j = 1; j <= m; ++j)
            if (s[i][j] == '*')
            {
                xmax = max(xmax, i);
                xmin = min(xmin, i);
                ymax = max(ymax, j);
                ymin = min(ymin, j);
            }
        }
        if (xmin != 1000000)
            printf("%d\n", max(xmax - xmin + 1, ymax - ymin + 1) / 2 + 1);
        else
            printf("0\n");
    }
    return 0;
}
