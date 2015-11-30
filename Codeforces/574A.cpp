#include <bits/stdc++.h>

using namespace std;

int n, a[100], c, res;

bool cmp(int a, int b) { return a > b; }

int main()
{
    cin >> n >> c;
    --n;
    res = 0;
    for (int i = 0; i < n; ++i) cin >> a[i];
    while (1)
    {
        sort(a,a+n,cmp);
        if (a[0] >= c)
        {
            ++res;
            ++c;
            --a[0];
        }
        else break;
    }
    cout << res;
    return 0;
}
