#include <bits/stdc++.h>

using namespace std;

int n, res, tmp, total;

int main()
{
    //freopen("aztec.in", "r", stdin);
    //freopen("aztec.out", "w", stdout);
    cin >> n;
    res = 1;
    tmp = total = 1;
    while (n > 0)
    {
        total += tmp*4;
        ++tmp;
        n -= total;
    }
    cout << tmp-1;
    return 0;
}
