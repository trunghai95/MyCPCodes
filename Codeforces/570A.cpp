#include <bits/stdc++.h>

using namespace std;

int n, m, cnt[111], _max, tmp, win;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        _max = -1;
        for (int j = 1; j <= n; ++j)
        {
            cin >> tmp;
            if (tmp > _max)
            {
                _max = tmp;
                win = j;
            }
        }
        ++cnt[win];
    }
    _max = -1;
    for (int i = 1; i <= n; ++i)
    {
        if (cnt[i] > _max)
        {
            _max = cnt[i];
            win = i;
        }
    }
    cout << win;
    return 0;
}
