#include <bits/stdc++.h>

using namespace std;

struct Position
{
    int x, y, dir;

    Position(int X, int Y, int Dir): x(X), y(Y), dir(Dir) {}
};

int dirX[] = { -1, 0, 1, 0};
int dirY[] = { 0, 1, 0, -1};

int curDir, posX, posY, res, w, h;
char mp[15][15];
vector<Position> poss;

bool avail(int x, int y)
{
    return (x >= 1 && x <= w && y >= 1 && y <= h && mp[x][y] != '*');
}

int main()
{

    cin >> w >> h;
    for (int i = 1; i <= w; ++i)
    {
        cin >> mp[i] + 1;
        for (int j = 1; j <= h; ++j)
        if (mp[i][j] != '.' && mp[i][j] != '*')
        {
            if (mp[i][j] == 'U') curDir = 0;
            else if (mp[i][j] == 'R') curDir = 1;
            else if (mp[i][j] == 'D') curDir = 2;
            else curDir = 3;
            posX = i; posY = j;
            mp[i][j] = 'c';
        }
    }

    res = 1;
    int f = 0;

    while(1)
    {
        if (f >= 4)
            break;

        int tmpX = posX + dirX[curDir], tmpY = posY + dirY[curDir];

        if (avail(tmpX, tmpY))
        {
            if (mp[tmpX][tmpY] == '.')
            {
                ++res;
                mp[tmpX][tmpY] = 'c';
            }
            f = 0;
            posX = tmpX;
            posY = tmpY;
            for (int i = 0; i < poss.size(); ++i)
            {
                if (posX == poss[i].x && posY == poss[i].y && curDir == poss[i].dir) { f = 4; break; }
            }
            poss.push_back(Position(tmpX, tmpY, curDir));
        }
        else
        {
            curDir = (curDir + 1) % 4;
            ++f;
        }
    }

    cout << res;
    return 0;
}
