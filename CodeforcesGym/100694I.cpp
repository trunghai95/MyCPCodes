#include <bits/stdc++.h>

using namespace std;

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

string name[1000], s;
int n, x, y, xg, yg, dir, i, tmp, t, _min, minPos;

int main()
{
    cin >> xg >> yg >> s;
    if (s == "LEFT")
        dir = LEFT;
    if (s == "RIGHT")
        dir = RIGHT;
    if (s == "UP")
        dir = UP;
    if (s == "DOWN")
        dir = DOWN;
    cin >> n;
    _min = 2000000000;
    minPos = -1;
    for (i = 0; i < n; ++i)
    {
        cin >> name[i] >> x >> y;
        switch (dir)
        {
        case LEFT:
            t = abs(y-yg)/2 + abs(y-yg)%2;
            tmp = xg - t;
            t += abs(x-tmp);
            if (t < _min)
            {
                _min = t;
                minPos = i;
            }
            break;
        case RIGHT:
            t = abs(y-yg)/2 + abs(y-yg)%2;
            tmp = xg + t;
            t += abs(x-tmp);
            if (t < _min)
            {
                _min = t;
                minPos = i;
            }
            break;
        case UP:
            t = abs(x-xg)/2 + abs(x-xg)%2;
            tmp = yg + t;
            t += abs(y-tmp);
            if (t < _min)
            {
                _min = t;
                minPos = i;
            }
            break;
        case DOWN:
            t = abs(x-xg)/2 + abs(x-xg)%2;
            tmp = yg - t;
            t += abs(y-tmp);
            if (t < _min)
            {
                _min = t;
                minPos = i;
            }
            break;
        }
    }
    cout << name[minPos];
    return 0;
}
