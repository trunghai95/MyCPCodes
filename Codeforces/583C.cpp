#include <bits/stdc++.h>

using namespace std;

int n, nn, g[300000];
map<int,int> cnt;
vector<int> res;
vector<int> a;

int main()
{
    //freopen("in.txt", "r", stdin);
    cin >> n;
    nn = n*n;
    for (int i = 0; i < nn; ++i)
    {
        cin >> g[i];
        ++cnt[g[i]];
        if (cnt[g[i]] == 1) a.push_back(g[i]);
    }

    sort(a.begin(), a.end());

    int i = a.size() - 1;

    while (1)
    {
        int cc = 0;

        while (cnt[a[i]])
        {
            ++cc;
            res.push_back(a[i]);
            for (int k = 0; k < res.size() && a[i] < res[k]; ++k)
                cnt[__gcd(a[i], res[k])] -= 2;

            if (cc*cc == cnt[a[i]])
            {
                cnt[a[i]] = 0;
                break;
            }
        }

        --i;

        if (i < 0) break;
    }

    for (int j = 0; j < res.size(); ++j)
        cout << res[j] << ' ';

    return 0;
}
