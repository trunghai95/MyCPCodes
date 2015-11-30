#include <bits/stdc++.h>

using namespace std;

bool valid[222];

void init()
{
    bool f[10][10];
    memset(f, 0, sizeof(f));
    memset(valid, 0, sizeof(valid));

    for (int i = 1; i <= 9; ++i)
    {
        if (i % 3) f[i][0] = 1;
        for (int j = i; j <= 9; ++j)
        {
            if ((j-1)%3 + 1 >= (i-1)%3 + 1)
                f[i][j] = 1;
        }
    }

    for (int i = 1; i <= 200; ++i)
    {
        if (i <= 9) valid[i] = 1;
        else if (i <= 99)
        {
            int a = i/10, b = i%10;
            if (f[a][b]) valid[i] = 1;
            else valid[i] = 0;
        }
        else
        {
            int a = i/100, b = (i/10) % 10, c = i%10;
            if (f[a][b] && f[b][c]) valid[i] = 1;
            else valid[i] = 0;
        }
    }
}

int main()
{
    init();
    int test, k;
    cin >> test;
    while (test--)
    {
        cin >> k;
        int d = 0;
        while (1)
        {
            if (valid[k - d])
            {
                cout << k - d << endl;
                break;
            }
            if (valid[k + d])
            {
                cout << k + d << endl;
                break;
            }
            ++d;
        }
    }
    return 0;
}
