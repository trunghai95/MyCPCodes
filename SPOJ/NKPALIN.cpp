#include <bits/stdc++.h>

using namespace std;

char s[3000];
int n, plen, l, r;
int f[3000][3000];
vector<int> res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> s;
    n = strlen(s);
    for (int i = 0; i < n; ++i)
        f[i][i] = 1;

    for (int i = n-2; i >= 0; --i)
    for (int j = i+1; j < n; ++j)
    {
        if (s[i] != s[j])
            f[i][j] = max(f[i+1][j], f[i][j-1]);
        else
        {
            if (j - i == 1) f[i][j] = 2;
            else f[i][j] = f[i+1][j-1] + 2;
        }
    }

    plen = f[0][n-1];
    l = 0;
    r = n-1;

    while (plen > 1)
    {
        while (f[l+1][r] == plen)
            ++l;
        while (f[l][r-1] == plen)
            --r;
        res.push_back(l);
        res.push_back(r);
        plen -= 2;
        ++l;
        --r;
    }
    if (plen == 1) res.push_back(l);

    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); ++i)
        cout << s[res[i]];
    return 0;
}
