#include <bits/stdc++.h>

using namespace std;

int a[101], n, m, last;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0, x, v; i < n; ++i)
    {
        cin >> x >> v;
        for (int i = 1; i <= x; ++i)
            a[last + i] = v;
        last += x;
    }

    int res = last = 0;
    for (int i = 0, x, v; i < m; ++i)
    {
        cin >> x >> v;
        for (int i = 1; i <= x; ++i)
            if (v > a[last + i]) res = max(res, v - a[last + i]);
        last += x;
    }

    cout << res;
    return 0;
}
