#include <bits/stdc++.h>

using namespace std;

int n, i, np, nn, x, y, res;
vector<int> pos, neg;
map<int,int> a;

int main()
{
    cin >> n;
    for (i = 0; i < n; ++i)
    {
        cin >> x >> y;
        a[x] = y;
        if (x > 0)
            pos.push_back(x);
        else
            neg.push_back(x);
    }
    sort(pos.begin(), pos.end());
    sort(neg.rbegin(), neg.rend());
    np = nn = min(pos.size(), neg.size());
    np += (pos.size() > neg.size());
    nn += (neg.size() > pos.size());
    res = 0;
    for (i = 0; i < np; ++i)
        res += a[pos[i]];
    for (i = 0; i < nn; ++i)
        res += a[neg[i]];

    cout << res;

    return 0;
}
