#include <bits/stdc++.h>

using namespace std;

int n, a[1111], res;

void proc(int l, int r)
{
    int mn = 2e9;
    for (int i = l; i <= r; ++i)
        mn = min(a[i], mn);

    for (int i = l; i <= r; ++i)
        a[i] -= mn;

    ++res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    while (1)
    {
        int l = -1, r = -1;

        for (int i = 0; i < n; ++i)
            if (a[i]) { l = i; break; }

        if (l == -1) break;

        r = n-1;
        for (int i = l+1; i < n; ++i)
            if (!a[i]) { r = i - 1; break; }

        proc(l,r);
    }

    cout << res;
    return 0;
}
