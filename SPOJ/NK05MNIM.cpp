#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, test;
    cin >> test;
    while (test--)
    {
        int res = 0;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> a;
            res = res ^ a;
        }
        cout << res << endl;
        if (res == 0) cout << -1 << endl;
        else cout << 1 << endl;
    }
    return 0;
}
