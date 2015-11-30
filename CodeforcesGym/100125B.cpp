#include <bits/stdc++.h>

using namespace std;

int x, y;
bool c[100][100];

int main()
{
    freopen("battleship.in", "r", stdin);
    freopen("battleship.out", "w", stdout);
    memset(c, 0, sizeof(c));
    int tmp;
    for (int i = 0; i < 10; ++i)
    for (int j = 0; j < 10; ++j)
    {
        cin >> tmp;
        if (tmp == 100)
            x = i, y = j;
    }
    c[x][y] = 1;
    int yt = y + 2, yg = y - 2;
    tmp = 1;
    while (tmp < 4 && yt < 10)
    {
        c[x][yt] = 1, ++tmp;
        yt += 2;
    }
    while (tmp < 4 && yg >= 0)
    {
        c[x][yg] = 1, ++tmp;
        yg -= 2;
    }
    tmp = 0;
    for (int i = 0; i < 10; i += 2)
    if (abs(i - x) >= 2)
    {
        if (tmp == 1)
        {
            c[i][0] = c[i][1] = c[i][2] = c[i][4] = c[i][5] = c[i][6] = 1;
            ++tmp;
        }
        else if (tmp == 0)
        {
            c[i][0] = c[i][1] = c[i][2] = c[i][3] = 1;
            c[i][5] = c[i][6] = c[i][8] = c[i][9] = 1;
            ++tmp;
        }
        else
        {
            c[i][0] = c[i][1] = 1;
            break;
        }
    }

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (c[i][j]) cout << '#';
            else cout << '.';
        }
        cout << endl;
    }
    return 0;
}
