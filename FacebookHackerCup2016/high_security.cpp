#include <bits/stdc++.h>

using namespace std;

int test, n;
char s[2][2000];

int main()
{
    //freopen("high_security.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &test);
    s[0][0] = s[1][0] = 0;

    for (int tt = 1; tt <= test; ++tt)
    {
        scanf("%d %s %s", &n, s[0] + 1, s[1] + 1);
        int res = 0;

        for (int i = 1; i <= n; ++i)
        {
            if (s[0][i] == '.' && s[0][i-1] != '.' && s[0][i+1] != '.')
            {
                ++res;
                s[0][i] = '*';
                if (s[1][i] == '.')
                {
                    s[1][i] = '*';
                    int j = i;
                    while (s[1][--j] == '.') s[1][j] = '*';
                    j = i;
                    while (s[1][++j] == '.') s[1][j] = '*';
                }
            }

            if (s[1][i] == '.' && s[1][i-1] != '.' && s[1][i+1] != '.')
            {
                ++res;
                s[1][i] = '*';
                if (s[0][i] == '.')
                {
                    s[0][i] = '*';
                    int j = i;
                    while (s[0][--j] == '.') s[0][j] = '*';
                    j = i;
                    while (s[0][++j] == '.') s[0][j] = '*';
                }
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            if (s[0][i] == '.')
            {
                ++res;
                while (s[0][++i] == '.');
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            if (s[1][i] == '.')
            {
                ++res;
                while (s[1][++i] == '.');
            }
        }

        printf("Case #%d: %d\n", tt, res);
    }
    return 0;
}
