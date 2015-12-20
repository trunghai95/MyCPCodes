#include <bits/stdc++.h>

using namespace std;

int a[1000], n, m;

bool cmp(const int& x, const int& y) { return x > y; }

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    sort(a+1, a+1+n, cmp);
    for (int i = 1; i <= n; ++i)
    {
        m -= a[i];
        if (m <= 0)
        {
            cout << i;
            return 0;
        }
    }

    cout << n;
    return 0;
}
