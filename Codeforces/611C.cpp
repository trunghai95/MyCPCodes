#include <bits/stdc++.h>

using namespace std;

int h, w, q, r1, c1, r2, c2, vf[600][600], hf[600][600];
char s[600][600];

int main()
{
    scanf("%d %d", &h, &w);
    for (int i = 1; i <= h; ++i)
        scanf("%s", s[i] + 1);
    for (int i = 1; i <= h; ++i)
    for (int j = 1; j <= w; ++j)
    {
        vf[i][j] = (s[i][j] == '.' && s[i+1][j] == '.') + vf[i][j-1];
        hf[i][j] = (s[i][j] == '.' && s[i][j+1] == '.') + hf[i][j-1];
    }
    for (int i = 1; i <= h; ++i)
    for (int j = 1; j <= w; ++j)
    {
        vf[i][j] += vf[i-1][j];
        hf[i][j] += hf[i-1][j];
    }

    scanf("%d", &q);
    while (q--)
    {
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        int res = 0;
        if (r2 > r1)
        {
            res += vf[r2-1][c2] - vf[r1-1][c2] - vf[r2-1][c1-1] + vf[r1-1][c1-1];
        }
        if (c2 > c1)
        {
            res += hf[r2][c2-1] - hf[r1-1][c2-1] - hf[r2][c1-1] + hf[r1-1][c1-1];
        }

        printf("%d\n", res);
    }

    return 0;
}
