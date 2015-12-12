#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test;
ll n, m, z, l, r, b;

int main()
{
    freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> test;

    while (test--)
    {
        cin >> n >> m >> z >> l >> r >> b;
        if (m == 1)
        {
            cout << min(z+l+r+b, n) << '\n';
            continue;
        }

        ll res = 0;
        ll sum = n*m;
        ll sumlr = l + r;
        ll tmp = min(sumlr / (m - 1), b);
        res += tmp * m;
        b -= tmp;
        sumlr -= tmp * (m - 1);

        if (res >= sum)
        {
            cout << sum << '\n';
            continue;
        }

        sum -= res;

        if (!b)
        {
            res += min(sumlr + z, sum);
            cout << res << '\n';
            continue;
        }

        //sumlr < m
        tmp = min(sumlr + 1, sum);
        --b;
        sum -= tmp;
        res += tmp;
        n = sum / m;
        ll le = sum % m;
        sum -= le;

        tmp = min(b, le/2);
        res += tmp; le -= tmp; b -= tmp;

        tmp = min(b, (m/2 + (m&1)) * n);
        sum -= tmp, res += tmp;
        res += min(z, sum + le);

        cout << res << '\n';
    }
    return 0;
}
