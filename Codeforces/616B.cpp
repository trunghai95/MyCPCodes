#include <bits/stdc++.h>

using namespace std;

int n, m, res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        int mn = 2e9;
        for (int j = 0, x; j < m; ++j)
        {
            cin >> x;
            mn = min(mn, x);
        }
        res = max(res, mn);
    }

    cout << res;
    return 0;
}
