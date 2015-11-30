#include <bits/stdc++.h>

using namespace std;

int n, m, res;
bool restrict[21][21];
vector<int> now;

void Try(int x)
{
    for (int i = 0; i < now.size(); ++i)
        if (restrict[now[i]][x]) return;

    ++res;
    now.push_back(x);

    for (int i = x + 1; i <= n; ++i)
        Try(i);

    now.pop_back();
}

int main()
{
    cin >> n >> m;
    memset(restrict, 0, sizeof(restrict));
    for (int i = 0, a, b; i < m; ++i)
    {
        cin >> a >> b;
        restrict[a][b] = restrict[b][a] = 1;
    }

    res = 1;
    for (int i = 1; i <= n; ++i)
        Try(i);

    cout << res;

    return 0;
}
