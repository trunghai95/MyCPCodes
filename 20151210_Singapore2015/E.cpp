#include <bits/stdc++.h>

using namespace std;

int n, p;
vector<int> a;

int main()
{
    cin >> n >> p;

    int f;
    for (int i = 0, x; i < n; ++i)
    {
        cin >> x;
        if (i == p) f = x;
        else a.push_back(x);
    }

    if (f > 300)
    {
        cout << "0 0";
        return 0;
    }

    int pen = f, numac = 1, curtime = f;

    sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); ++i)
    {
        if (curtime + a[i] <= 300)
            curtime += a[i], pen += curtime, ++numac;
        else break;
    }

    cout << numac << ' ' << pen;
    return 0;
}
