#include <bits/stdc++.h>

using namespace std;

int n, m, i, l, r, cp, cn, tmp;

int main()
{
    cin >> n >> m;
    cp = 0;
    cn = 0;

    for (i = 0; i < n; ++i)
    {
        cin >> tmp;
        if (tmp > 0)
            ++cp;
        else
            ++cn;
    }

    while (m-- > 0)
    {
        cin >> l >> r;
        tmp = r - l + 1;
        if (tmp&1)
        {
            cout << 0 << endl;
            continue;
        }
        tmp /= 2;
        if (cp >= tmp && cn >= tmp)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
