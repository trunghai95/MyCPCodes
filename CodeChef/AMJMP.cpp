#include <bits/stdc++.h>

using namespace std;

int jmp[5001][5001];
int h[5001], n;

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", h+i);
    if (n == 1)
    {
        printf("0");
        return 0;
    }

    int tmp;
    for (int dis = 1; dis < n; ++dis)
    {
        for (int i = 1; i <= n; ++i)
        {
            if ((tmp = i + dis) <= n)
            {
                if (h[i] <= h[tmp]) jmp[i][tmp] = 0;
                else jmp[i][tmp] = 1 + jmp[tmp][i + 1];
                jmp[i][tmp] = max(jmp[i][tmp], jmp[i][tmp - 1]);
            }

            if ((tmp = i - dis) > 0)
            {
                if (h[i] <= h[tmp]) jmp[i][tmp] = 0;
                else jmp[i][tmp] = 1 + jmp[tmp][i - 1];
                jmp[i][tmp] = max(jmp[i][tmp], jmp[i][tmp + 1]);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        printf("%d ", max(jmp[i][n], jmp[i][1]));
    return 0;
}
