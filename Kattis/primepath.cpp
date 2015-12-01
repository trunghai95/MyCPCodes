#include <bits/stdc++.h>

using namespace std;

int ck[10000];
vector<int> pr;
map<int,int> id;
bool e[6000][6000];

bool cmp(int x, int y)
{
    int cnt = 0;
    while (x && y)
    {
        if (x % 10 != y % 10)
            ++cnt;
        x /= 10;
        y /= 10;
    }

    return (cnt == 1);
}

void init()
{
    for (int i = 2; i < 10000; ++i)
    if (!ck[i])
    {
        for (int j = i*i; j < 10000; j += i)
            ck[j] = true;
    }

    for (int i = 1001; i < 10000; i += 2)
    if (!ck[i])
    {
        int ii = id[i] = pr.size();
        pr.push_back(i);

        for (int j = 0; j < ii; ++j)
        if (cmp(pr[j], pr[ii]))
            e[j][ii] = e[ii][j] = 1;
    }
}

int solve(int x, int y)
{
    x = id[x];
    y = id[y];

    memset(ck, -1, sizeof(ck));
    ck[x] = 0;
    queue<int> q;
    q.push(x);

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        if (u == y)
            return ck[y];

        for (int i = 0; i < pr.size(); ++i)
        if (e[i][u] && ck[i] == -1)
            q.push(i), ck[i] = ck[u] + 1;
    }

    return -1;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    init();
    int test, x, y;

    cin >> test;
    while (test--)
    {
        cin >> x >> y;
        int res = solve(x, y);
        if (res < 0)
            cout << "Impossible\n";
        else
            cout << res << '\n';
    }
    return 0;
}
