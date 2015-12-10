#include <bits/stdc++.h>

using namespace std;

int a[3], b[3];

int main()
{
    for (int i = 0; i < 3; ++i)
        cin >> a[i];
    for (int i = 0; i < 3; ++i)
        cin >> b[i];

    int s = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (a[i] > b[i]) s += (a[i] - b[i]) / 2;
        else s -= (b[i] - a[i]);
    }

    if (s >= 0) cout << "Yes";
    else cout << "No";
    return 0;
}
