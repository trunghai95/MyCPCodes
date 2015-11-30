#include <bits/stdc++.h>

using namespace std;

int main()
{
    int d1, d2, d3;
    int res;

    cin >> d1 >> d2 >> d3;
    res = d1 + d2 + d3;
    res = min(res, 2*(d1 + d3));
    res = min(res, 2*(d2 + d3));
    res = min(res, 2*(d1 + d2));
    cout << res;
    return 0;
}
