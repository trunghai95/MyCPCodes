#include <bits/stdc++.h>

using namespace std;

int cnt[7], id[7], n, x;

int main()
{
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        ++cnt[x];
        id[x] = i;
    }

    for (int i = 6; i >= 1; --i)
    if (cnt[i] == 1)
    {
        cout << id[i];
        return 0;
    }

    cout << "none";
    return 0;
}
