#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;

int n, m, a, b, t[MAX];

void update(int x)
{
    while (x <= MAX)
    {
        ++t[x];
        x += (x&(-x));
    }
}

int get(int x)
{
    int res = 0;
    while (x > 0)
    {
        res += t[x];
        x -= x&(-x);
    }
    return res;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        update(a);
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> b;
        cout << get(b) << endl;
    }
    return 0;
}
