#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;

int bit[4][100010];
int n, q;

void update(int id, int x)
{
    while (x <= n)
    {
        ++bit[id][x];
        x += x&(-x);
    }
}

int get(int id, int x)
{
    int res = 0;
    while (x > 0)
    {
        res += bit[id][x];
        x -= x&(-x);
    }
    return res;
}

int main()
{
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    scanf("%d %d", &n, &q);
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        update(x, i);
    }

    for (int i = 1, u, v; i <= q; ++i)
    {
        scanf("%d %d", &u, &v);
        cout << get(1, v) - get(1, u-1) << ' ' << get(2, v) - get(2, u-1) << ' ' << get(3, v) - get(3, u-1) << '\n';
    }
    return 0;
}
