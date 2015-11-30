#include <bits/stdc++.h>

using namespace std;

int w, s, h[10010][110], ss[110], x, y, tmp;

int main()
{
    cin >> w >> s >> x >> y;
    for (int i = 0; i < x; ++i)
        ss[i] = 2e9;

    for (int i = 0; i < w; ++i)
    for (int j = 0; j < x; ++j)
        cin >> h[i][j];

    for (int i = 0; i < s; ++i)
    for (int j = 0; j < x; ++j)
    {
        cin >> tmp;
        tmp = y - tmp;
        ss[j] = min(ss[j], tmp);
    }

    for (int i = 0; i < w; ++i)
    {
        for (int j = 0; j < x; ++j)
        {
            tmp = min(ss[j], h[i][j]);
            cout << tmp << ' ';
        }
        cout << endl;
    }
    return 0;
}
