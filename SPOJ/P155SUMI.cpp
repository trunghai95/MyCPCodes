#include <bits/stdc++.h>

using namespace std;

int n, m, res = 1e9, tmp, Max, Min;
vector<int> a;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m-n; ++i)
    {
        tmp = a[i+n-1] - a[i];
        if (tmp < res) res = tmp;
    }
    cout << res;
    return 0;
}
