#include <bits/stdc++.h>

using namespace std;

int n, m, res, s;

int main()
{
    cin >> n >> m;
    res = 0;
    for (int i = 0; i < m; ++i)
    {
        cin >> s;
        res += s%n;
        if (res >= n) res -= n;
    }

    cout << res;
    return 0;
}
