#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int x;
string s;

int main()
{
    cin >> x >> s;
    cin >> s;

    if (s[0] == 'm')
    {
        if (x == 31)
            cout << 7;
        else if (x == 30)
            cout << 11;
        else
            cout << 12;
        return 0;
    }

    if (x == 5 || x == 6)
        cout << 53;
    else cout << 52;

    return 0;
}
