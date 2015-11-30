#include <bits/stdc++.h>

using namespace std;

int n, res, i;
string s1, s2;

int main()
{
    cin >> n >> s1;
    res = 1;
    for (i = 1; i < n; ++i)
    {
        cin >> s2;
        if (s1 != s2)
            ++res;
        s1 = s2;
    }
    cout << res;
    return 0;
}
