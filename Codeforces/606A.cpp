#include <bits/stdc++.h>

using namespace std;

int a[3], b[3];

int main()
{
    int op = 0;

    for (int i = 0; i < 3; ++i)
        cin >> a[i], op += a[i];
    for (int i = 0; i < 3; ++i)
        cin >> b[i], op -= b[i];

    if (op < 0)
    {
        cout << "No";
        return 0;
    }

    int ss = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (a[i] < b[i]) ss += b[i] - a[i];
        else
            ss += (a[i] - b[i])/2 + 2*((a[i] - b[i]) & 1);
    }

    ss /= 2;

    if (ss == op)
        cout << "Yes";
    else cout << "No";
    return 0;
}
