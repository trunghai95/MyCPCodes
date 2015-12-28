// WA
#include <bits/stdc++.h>

using namespace std;

int n, c[501], f[501][501];

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];

    for (int j = 1; j <= n; ++j)
    {
        f[j][j] = 1;

        for (int i = j - 1; i >= 1; --i)
        {
            f[i][j] = min(f[i+1][j], f[i][j-1]) + 1;
            for (int k = i + 2; k <= j; ++k)
            if (c[i] == c[k])
                f[i][j] = min(f[i][j], f[i+1][k-1] + f[k+1][j]);
            if (c[i] == c[i+1]) f[i][j] = 1 + f[i+2][j];
        }
    }

    cout << f[1][n];
    return 0;
}
