//WA
#include <bits/stdc++.h>

using namespace std;

int a[501], n;
int f[501][501];

void init()
{
    for (int i = 0; i < n; ++i)
        f[i][i] = 1;

    for (int i = n - 2; i >= 0; --i)
    for (int j = i + 1; j < n; ++j)
    {
        if (a[i] != a[j])
            f[i][j] = max(f[i+1][j], f[i][j-1]);
        else
        {
            if (j - i == 1) f[i][j] = 2;
            else f[i][j] = f[i+1][j-1] + 2;
        }
    }
}

int Solve(int lef, int rig)
{
    int plen = f[lef][rig];
    if (plen == 1) return (rig - lef + 1);
    if (plen == (rig - lef + 1)) return 1;

    int l = lef, r = rig;

    while (plen > 1)
    {
        while (f[l+1][r] == plen)
            ++l;
        while (f[l][r-1] == plen)
            --r;
//        res.push_back(l);
//        res.push_back(r);
        a[l] = a[r] = -1;
        plen -= 2;
        ++l;
        --r;
    }
    if (plen == 1) a[l] = -1;

    l = lef;
    int res = 1;

    while (1)
    {
        while (l <= rig && a[l] == -1) ++l;
        if (l > rig) break;
        r = l;
        while (r <= rig && a[r] != -1) ++r;
        --r;
        res += Solve(l, r);
        l = r + 1;
    }

    return res;
}

int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a+i);
    init();
    int res = Solve(0, n-1);

    printf("%d", res);
    return 0;
}
