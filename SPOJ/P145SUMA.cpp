#include <bits/stdc++.h>

using namespace std;

int n, i, m, r1, r2;
char s[60];

int main()
{
    cin >> n >> s;
    if (n&1)
    {
        cout << "NO";
        return 0;
    }
    m = n/2;
    for (i = 0; i < m; ++i)
    {
        if ((s[i] != '7' && s[i] != '4') || (s[i+m] != '7' && s[i+m] != '4'))
        {
            cout << "NO";
            return 0;
        }
        r1 += s[i];
        r2 += s[i+m];
    }
    if (r1 == r2)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
