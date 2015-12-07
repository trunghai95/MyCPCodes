#include <bits/stdc++.h>

using namespace std;

bool mp[200][200];
int n, k;

int main()
{
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n && k; ++i)
    for (int j = ((i - 1) & 1) + 1; j <= n && k; j += 2)
    {
        mp[i][j] = true;
        --k;
    }

    if (k) printf("NO");
    else
    {
        printf("YES\n");
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
                printf("%c", mp[i][j]?'L':'S');
            printf("\n");
        }
    }
    return 0;
}
