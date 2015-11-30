#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 1000000;
int n;
ll a[MAXN], p;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> p;

    for (int i = 0; i < n; ++i)
        a[i] -= p;

    int dau = 0, cuoi = 0;
    ll sum = a[dau];
    int res = 0;

    while (dau < n)
    {
        res += (a[dau] >= 0);

        if (cuoi > dau) res += (sum >= 0);

        if (cuoi <= dau)
        {
            for (cuoi = dau + 1; cuoi < n; ++cuoi)
            {
                sum += a[cuoi];
                res += (sum >= 0);
            }
        }

        else
        {
            for (cuoi = n - 2; cuoi > dau; --cuoi)
            {
                sum -= a[cuoi + 1];
                res += (sum >= 0);
            }
        }

        sum -= a[dau];
        ++dau;
    }

    cout << res;
    return 0;
}
