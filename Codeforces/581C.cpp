#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int n, k, res;
pii a[100001];

bool cmp1(pii x, pii y)
{
    return x.second > y.second;
}

int main()
{
    cin >> n >> k;
    res = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = a[i].first % 10;
        res += a[i].first/10;
    }

    sort(a,a+n,cmp1);
    int i = 0;
    while (1)
    {
        if (a[i].second == 0 || k == 0) break;
        int tmp = min(k,10 - a[i].second);
        res -= a[i].first / 10;
        a[i].first += tmp;
        res += a[i].first / 10;
        ++i;
        k -= tmp;
    }

    sort(a,a+n);
    for (int i = 0; i < n && k > 0 && a[i].first < 100; ++i)
    {
        int tmp = min(100 - a[i].first, k);
        k -= tmp;
        a[i].first += tmp;
        res += tmp / 10;
    }

    cout << res;
    return 0;
}
