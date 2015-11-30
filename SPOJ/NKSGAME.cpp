#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;
int n, b[MAX], c[MAX], res;

int abs(int x) { return x > 0? x : -x; }

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i)
        cin >> c[i];

    sort(c,c+n);
    res = 2e9;

    for (int i = 0; i < n; ++i)
    {
        int p = lower_bound(c, c + n, -b[i]) - c, tmp;
        if (p == n) tmp = abs(b[i] + c[p-1]);
        else if (p == 0) tmp = abs(b[i] + c[0]);
        else tmp = min(abs(b[i] + c[p]), abs(b[i] + c[p-1]));
        res = min(res, tmp);
    }

    cout << res;

    return 0;
}
