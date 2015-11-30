#include <bits/stdc++.h>

using namespace std;

const int MAXN = 60000;
const int INF = 2e9;
int n, t[MAXN], r[MAXN], f[MAXN][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> t[i];
    for (int i = 0; i < n-1; ++i)
        cin >> r[i];

    f[0][0] = INF;
    f[0][1] = t[0];
    f[1][0] = r[0];
    f[1][1] = t[1] + t[0];

    for (int i = 2; i < n; ++i)
    {
        f[i][0] = f[i-1][1] - t[i-1] + r[i-1];
        f[i][1] = min(f[i-1][0], f[i-1][1]) + t[i];
    }

    cout << min(f[n-1][0], f[n-1][1]);
    return 0;
}
