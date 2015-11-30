#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;
    cin >> n >> m;

    int res = 0;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
    {
        int a, b;
        cin >> a >> b;
        res += a | b;
    }

    cout << res;
    return 0;
}
