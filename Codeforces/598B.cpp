#include <bits/stdc++.h>

using namespace std;

string s, stmp;
int m, l, r, k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> s >> m;
    while (m--)
    {
        cin >> l >> r >> k;
        --l, --r;
        int len = r - l + 1;
        k %= len;
        stmp = s;
        for (int i = l; i <= r; ++i)
        {
            s[i] = stmp[(i - l - k + len) % len + l];
        }
    }
    cout << s;
    return 0;
}
