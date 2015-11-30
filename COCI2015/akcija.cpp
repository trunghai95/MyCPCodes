#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, c[100000];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> n;

    for (ll i = 0; i < n; ++i)
        cin >> c[i];

    sort(c, c+n);

    ll res = 0;
    for (ll i = n-1; i >= 0; --i)
    {
        if (i >= 2)
        {
            res += c[i] + c[i-1];
            i -= 2;
        }
        else
            res += c[i];
    }
    cout << res;
    return 0;
}
