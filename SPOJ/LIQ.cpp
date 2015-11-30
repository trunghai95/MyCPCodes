#include <bits/stdc++.h>

using namespace std;

int a[1000], f[1000], n, res;

int main()
{
    cin >> n;
    res = 1;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        for (int j = i-1; j >= 0; --j)
        if (a[i] > a[j]) f[i] = max(f[i], f[j]);
        ++f[i];
        res = max(res,f[i]);
    }
    cout << res;
    return 0;
}
