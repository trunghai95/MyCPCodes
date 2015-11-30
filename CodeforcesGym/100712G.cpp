#include <bits/stdc++.h>

using namespace std;

int t, n, s, c[11], sum, cnt;

int main()
{
    cin >> t;
    while (t--)
    {
        sum = cnt = 0;
        cin >> n >> s;
        for (int i = 0; i < n; ++i)
            cin >> c[i];
        sort(c,c+n);
        for (int i = 0; i < n; ++i)
        {
            sum += c[i];
            ++cnt;
            if (sum >= s)
                break;
        }
        for (int i = cnt - 1; i >= 0; --i)
        {
            if (sum - c[i] >= s)
            {
                sum -= c[i];
                --cnt;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
