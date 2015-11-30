#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

int n, i, tmp, x, x1, x2;
vector<int> mxPos;
pair<int,pii> a[1000000];

int main()
{
    cin >> n;
    memset(a, 0, sizeof(a));
    x = 0;
    for (i = 1; i <= n; ++i)
    {
        cin >> tmp;
        ++a[tmp].first;
        a[tmp].second.second = i;
        if (a[tmp].second.first == 0)
            a[tmp].second.first = i;
        if (a[tmp].first > x)
        {
            mxPos.clear();
            mxPos.push_back(tmp);
            x = a[tmp].first;
        }
        if (a[tmp].first == x)
            mxPos.push_back(tmp);
    }

    x1 = a[mxPos[0]].second.first;
    x2 = a[mxPos[0]].second.second;

    for (i = 1; i < mxPos.size(); ++i)
        if ((a[mxPos[i]].second.second - a[mxPos[i]].second.first) < (x2 - x1))
        {
            x2 = a[mxPos[i]].second.second;
            x1 = a[mxPos[i]].second.first;
        }
    cout << x1 << " " << x2;;
    return 0;
}
