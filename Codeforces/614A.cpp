#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll l, r, k;

int main()
{
//    freopen("in.txt", "r", stdin);
    cin >> l >> r >> k;

    bool f = false;
    ll n = 1;

    while (1)
    {
        if (n >= l)
            cout << n << ' ', f = true;
        if (n <= r/k)
            n *= k;
        else break;
    }

    if (!f)
        cout << "-1";

    return 0;
}
