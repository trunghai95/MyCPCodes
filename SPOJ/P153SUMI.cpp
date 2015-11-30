#include <bits/stdc++.h>

using namespace std;

int n, a[100000], i, tmp, res;

int main()
{
    tmp = -1;

    cin >> n >> a[0];

    for (i = 1; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] < a[i-1])
        {
            if (tmp != -1)
            {
                cout << -1;
                return 0;
            }
            tmp = i;
        }
    }

    if (tmp == -1)
        res = 0;
    else
    {
        if (a[n-1] > a[0])
            res = -1;
        else
            res = n-tmp;
    }

    cout << res;

    return 0;
}
