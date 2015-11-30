#include <bits/stdc++.h>

using namespace std;

long long n, x, y, res;

long long& change(long long &x, long long &y)
{
    if (x < y)
        return x = x+y;
    else
        return y = x+y;
}

int main()
{
    cin >> x >> y >> n;
    if (x >= n || y >= n)
    {
        cout << 0;
        return 0;
    }
    if (x <= 0 && y <= 0)
    {
        cout << -1;
        return 0;
    }
    res = 1;
    while (change(x,y) < n)
        ++res;
    cout << res;
    return 0;
}
