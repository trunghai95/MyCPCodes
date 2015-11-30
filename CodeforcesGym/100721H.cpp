#include <bits/stdc++.h>

using namespace std;

struct People
{
    int h;
    char sex;
    string music, sport;
} tmp;

int t, n, res1, res2;
vector<People> g[2];

int calc(int t)
{
    int res = g[t].size(), i, j;
    for (i = 0; i < g[1-t].size(); ++i)
    {
        for (j = 0; j < g[t].size(); ++j)
            if (abs(g[t][j].h - g[1-t][i].h) <= 40 && g[t][j].music == g[1-t][i].music && g[t][j].sport != g[1-t][i].sport)
                break;
        if (j == g[t].size())
            ++res;
    }
    return res;
}

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> t;

    while (t--)
    {
        g[0].clear();
        g[1].clear();
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> tmp.h >> tmp.sex >> tmp.music >> tmp.sport;
            if (tmp.sex == 'F')
                g[0].push_back(tmp);
            else
                g[1].push_back(tmp);
        }
        res1 = calc(0);
        res2 = calc(1);
        if (res1 > res2)
            cout << res1 << endl;
        else
            cout << res2 << endl;
    }
    return 0;
}
