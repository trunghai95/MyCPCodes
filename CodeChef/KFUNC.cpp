#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test;
ll a, d, l, r;

ll remain[10], s[10];

int main()
{
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> test;
    while (test--)
    {
        cin >> a >> d >> l >> r;
        ll sumr = remain[0] = (a + (d % 9)*(l - 1) - 1) % 9 + 1;
        s[0] = 0;
        for (ll i = 1; i < 9; ++i)
            sumr += (remain[i] = (remain[i-1] + d - 1) % 9 + 1), s[i] = s[i-1] + remain[i-1];

        ll res = (r - l + 1) / 9 * sumr + s[(r - l + 1) % 9];
        cout << res << endl;
    }
    return 0;
}
