#include <bits/stdc++.h>

using namespace std;

int n, t, a[111], m, res;

int main()
{
    cin >> t;
    while (t--)
    {
        m = res = 0;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (a[i] > m)
                m = a[i];
        }
        m = 100 - m;
        for (int i = 0; i < n; ++i)
        {
            a[i] += m;
            if (a[i] >= 50)
                ++res;
        }
        cout << res << endl;
    }
    return 0;
}
