#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin >> n;

    if (n & 1)
    {
        cout << 0;
        return 0;
    }

    cout << (n >> 2) - !((n >> 1) & 1);
    return 0;
}
