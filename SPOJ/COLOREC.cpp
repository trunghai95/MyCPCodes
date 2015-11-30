#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

vector<int> column[401];
int color[401][401];
int f[5][5];
int n;

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0, x, y, k; i < n; ++i)
    {
        scanf("%d %d %d", &x, &y, &k);
        x += 200;
        y += 200;
        color[x][y] = k;
        column[x].push_back(y);
    }

    int res = 0;

    for (int x1 = 0; x1 <= 400; ++x1)
    if (column[x1].size() >= 2)
    for (int x2 = x1 + 1; x2 <= 400; ++x2)
    if (column[x2].size() >= 2)
    {
        memset(f, 0, sizeof(f));
        for (int i = 0; i < column[x1].size(); ++i)
        {
            int y = column[x1][i];
            ++f[color[x1][y]][color[x2][y]];
            ++f[color[x2][y]][color[x1][y]];
        }

        res += f[1][2]*f[3][4] + f[1][3]*f[2][4] + f[1][4]*f[2][3];
    }

    printf("%d", res);

    return 0;
}
