#include <bits/stdc++.h>

using namespace std;

int test, w[1001], n;
string a, b;

int main()
{
    cin >> test;
    while (test--)
    {
        int cnt = 0;
        cin >> n >> a >> b >> w[0];
        for (int i = 0; i < n; ++i)
        {
            cnt += (a[i] == b[i]);
            cin >> w[i+1];
        }

        if (cnt == n) { cout << w[n] << endl; continue; }

        int res = 0;
        for (int i = 0; i <= cnt; ++i)
            res = max(res, w[i]);

        cout << res << endl;
    }
    return 0;
}
