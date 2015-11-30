#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, m;
    string s, step;
    cin >> n >> x >> s >> m >> step;

    --x;
    cout << s[x];
    for (int i = 0; i < m; ++i)
    {
        if (step[i] == 'R')
            cout << s[++x];
        else cout << s[--x];
    }
    return 0;
}
