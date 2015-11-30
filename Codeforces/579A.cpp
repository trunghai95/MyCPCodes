#include <bits/stdc++.h>

using namespace std;

int x, res;

int main()
{
    cin >> x;
    res = 0;
    while (x)
    {
        res += x&1;
        x >>= 1;
    }
    cout << res;
    return 0;
}
