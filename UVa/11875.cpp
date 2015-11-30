#include <bits/stdc++.h>

using namespace std;

int t, n, a[11];

int main()
{
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cin >> n;
        for (int j = 0; j < n; ++j)
            cin >> a[j];
        printf("Case %d: %d\n",i,a[n/2]);
    }
    return 0;
}
