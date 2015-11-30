#include <bits/stdc++.h>

using namespace std;

int t, n, a, sum;

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n;
        sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a;
            sum += a;
        }

        if (sum % n || !sum)
            cout << -1 << endl;
        else cout << sum/n << endl;
    }
    return 0;
}
