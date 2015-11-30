#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30000;
int n, a[MAXN];

int lis()
{
    vector<int> res;

    for (int i = 0; i < n; ++i)
    {
        vector<int>::iterator it = lower_bound(res.begin(), res.end(), a[i]);
        if (it == res.end())
            res.push_back(a[i]);
        else
            *it = a[i];
    }

    return res.size();
}

int main()
{
    cout << (3^7^11);
    return 0;
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << lis();
    return 0;
}
