#include <bits/stdc++.h>

using namespace std;

int n;
bool a[60], b[60];

int main()
{
    cin >> n;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));

    n*=n;
    int x, y;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x >> y;
        if (!a[x] && !b[y])
        {
            cout << i << ' ';
            a[x] = b[y] = 1;
        }
    }
    return 0;
}
