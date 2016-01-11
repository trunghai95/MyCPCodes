#include <bits/stdc++.h>

using namespace std;

int m, n;
bool ck[200];

int main()
{
    cin >> n >> m;

    for (int i = 0, x, y; i < n; ++i)
    {
        cin >> x;
        while (x--)
        {
            cin >> y;
            ck[y] = true;
        }
    }

    for (int i = 1; i <= m; ++i)
    if (!ck[i])
    {
        cout << "NO";
        return 0;
    }

    cout << "YES";
    return 0;
}
