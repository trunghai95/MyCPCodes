#include <bits/stdc++.h>

using namespace std;

int tc, m, c, k[20], s[201][20], a[20][20], res;
bool ck[201][20];

int shop(int money, int gar)
{
    if (gar == c)
        return m-money;

    if (ck[money][gar])
        return s[money][gar];
    ck[money][gar] = 1;
    int tmp, res=0;
    for (int i = 0; i < k[gar]; ++i)
        if (a[gar][i] <= money)
        {
            tmp = shop(money-a[gar][i],gar+1);
            if (tmp > res)
                res = tmp;
        }
    return s[money][gar] = res;
}

int main()
{
    cin >> tc;
    while (tc--)
    {
        cin >> m >> c;
        for (int i = 0; i < c; ++i)
        {
            cin >> k[i];
            for (int j = 0; j < k[i]; ++j)
                cin >> a[i][j];
        }
        memset(ck,0,sizeof(ck));
        res = 0;
        res = shop(m,0);
        if (res == 0)
            cout << "no solution\n";
        else
            cout << res << endl;
    }
    return 0;
}
