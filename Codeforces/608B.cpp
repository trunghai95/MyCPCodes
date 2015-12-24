#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string a, b;
ll cnt[200010];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> a >> b;

    cnt[0] = (b[0] == '1');
    for (int i = 1; i < b.length(); ++i)
        cnt[i] = cnt[i-1] + (b[i] == '1');

    ll res = 0;

    for (int i = 0; i < a.length(); ++i)
    {
        int l = i, r = b.length() - a.length() + i;
        ll tmp = cnt[r] - ((l > 0) ? cnt[l-1] : 0);
        if (a[i] == '0')
            res += tmp;
        else
            res += r - l + 1 - tmp;
    }

    cout << res;
    return 0;
}
