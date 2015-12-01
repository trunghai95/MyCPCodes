#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    int l = -1, r = -1;

    for (int i = 1; i < n; ++i)
    if (s[i] == s[i-1])
    {
        if (l == -1)
            l = i;
        else
            r = i-1;
    }

    if (l != -1)
    {
        if (r == -1) r = n-1;

        for (int i = l; i <= r; ++i)
        {
            if (s[i] == '0')
                s[i] = '1';
            else s[i] = '0';
        }
    }

    int lastdig = s[0], cnt = 1;

    for (int i = 1; i < n; ++i)
    if (s[i] != lastdig)
    {
        lastdig = s[i];
        ++cnt;
    }

    cout << cnt;
    return 0;
}
