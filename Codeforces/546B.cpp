#include <bits/stdc++.h>

using namespace std;

int n, a[4000], res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    sort(a+1, a+n+1);
    for (int i = 2; i <= n; ++i)
    {
        while (a[i] <= a[i-1])
            ++res, ++a[i];
    }

    cout << res;
    return 0;
}
