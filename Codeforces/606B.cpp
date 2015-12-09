#include <bits/stdc++.h>

using namespace std;

int x, y, curx, cury;
bool ck[600][600];
char s[200000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> x >> y >> curx >> cury >> s;
    int sum = x*y - 1;
    int i = 0;
    cout << "1 ";
    ck[curx][cury] = true;

    while (s[i + 1] != 0)
    {
        if (s[i] == 'U' && curx > 1)
            --curx;
        else if (s[i] == 'D' && curx < x)
            ++curx;
        else if (s[i] == 'L' && cury > 1)
            --cury;
        else if (s[i] == 'R' && cury < y)
            ++cury;

        if (!ck[curx][cury])
            cout << "1 ", --sum, ck[curx][cury] = true;
        else cout << "0 ";

        ++i;
    }

    cout << sum;
    return 0;
}
