#include <bits/stdc++.h>

using namespace std;

char a[3000], b[3000];
int f[3000][3000];

int main()
{
    scanf("%s %s", a+1, b+1);
    int la = strlen(a+1);
    int lb = strlen(b+1);
    memset(f, 0, sizeof(f));

    for (int i = 1; i <= la; ++i)
    for (int j = 1; j <= lb; ++j)
    {
        if (a[i] == b[j])
            f[i][j] = f[i-1][j-1] + 1;
        else f[i][j] = max(f[i-1][j], f[i][j-1]);
    }

    printf("%d", f[la][lb]);
    return 0;
}
