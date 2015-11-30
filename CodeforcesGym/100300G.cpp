#include <bits/stdc++.h>

using namespace std;

int test, n, m, dir, cnt;
char s[11][11];
int dirX[] = {0,1,1,1};
int dirY[] = {1,1,0,-1};

bool check(int x, int y)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    cin >> test;

    while (test--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            cin >> s[i];
        cnt = 0;
        for (int i = 0; i < n && !cnt; ++i)
        {
            for (int j = 0; j < m; ++j)
            if (s[i][j] != '.')
            {
                switch (s[i][j])
                {
                    case '-': dir = 0; break;
                    case '\\': dir = 1; break;
                    case '|': dir = 2; break;
                    case '/': dir = 3; break;
                }

                int xx = i + dirX[dir], yy = j + dirY[dir];
                while (check(xx, yy))
                {
                    if (s[xx][yy] != s[i][j]) break;
                    s[xx][yy] = '.';
                    xx += dirX[dir]; yy += dirY[dir];
                }

                xx = i - dirX[dir], yy = j - dirY[dir];
                while (check(xx, yy))
                {
                    if (s[xx][yy] != s[i][j]) break;
                    s[xx][yy] = '.';
                    xx -= dirX[dir]; yy -= dirY[dir];
                }
                s[i][j] = '.';
                ++cnt;
                break;
            }
        }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (s[i][j] != '.') cnt = 0;

        if (!cnt) cout << "INCORRECT\n";
        else cout << "CORRECT\n";
    }
}
