#include <bits/stdc++.h>

using namespace std;

int n, k;
int a, sum[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    memset(sum, 0, sizeof(sum));

    for (int i = 1; i <= n; ++i)
    {
        int sumr = 0;
        for (int j = 1; j <= n; ++j)
        {
            cin >> a;
            sumr += a;
            sum[i][j] = sum[i-1][j] + sumr;
        }
    }

    int res = 0;
    for (int i = k; i <= n; ++i)
    for (int j = k; j <= n; ++j)
        res = max(res, sum[i][j] - sum[i][j-k] - sum[i-k][j] + sum[i-k][j-k]);

    cout << res;
    return 0;
}
