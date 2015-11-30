#include <bits/stdc++.h>

using namespace std;

int n, m, k, w[100007], f[100007], i, j, cnt;
vector<vector<int> > res;

int main()
{
    cin >> n >> m >> k;

    for (i = 0; i < n; ++i)
        cin >> w[i];

    for (i = 0; i < m; ++i)
        cin >> f[i];

    j = cnt = 0;

    while (1)
    {
        if (w[0] == f[j])
            break;
        ++j;
    }

    res.push_back(vector<int>());
    res[0].push_back(1);
    i = 1;
    ++j;

    while (1)
    {
        if (w[i] == f[j])
        {
            if (res[cnt].size() == k)
            {
                ++cnt;
                res.push_back(vector<int>());
            }
            res[cnt].push_back(i+1);
        }
        else
        {
            res.push_back(vector<int>());
            ++cnt;
            while (1)
            {
                ++j;
                if (w[i] == f[j])
                    break;
            }
            res[cnt].push_back(i+1);
        }
        ++i;
        ++j;
        if (i == n)
            break;
    }

    cout << ++cnt << endl;
    for (i = 0; i < cnt; ++i)
    {
        cout << res[i].size();
        for (j = 0; j < res[i].size(); ++j)
            cout << " " << res[i][j];
        cout << endl;
    }

    return 0;
}
