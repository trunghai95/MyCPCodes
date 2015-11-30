#include <bits/stdc++.h>

using namespace std;

int n, a[1111];
bool ck[1111];

int main()
{
    cin >> n;
    memset(ck, 0, sizeof(ck));
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (n == 1) { cout << 0; return 0; }

    int cnt = 0, dir = 1, res = 0, i = 0;

    while (cnt != n)
    {
        i += dir;
        if (i > n || i < 1) { dir = - dir; i += dir; ++res; }

        if (!ck[i] && a[i] <= cnt)
        {
            ck[i] = 1;
            ++cnt;
        }
    }

    cout << res;
    return 0;
}
