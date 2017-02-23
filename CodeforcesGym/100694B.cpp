#include <bits/stdc++.h>

using namespace std;

int p, n, x;

int getCol(int x) {
    return x/p + 1;
}

int getRow(int x) {
    return x%p + 1;
}

int main()
{
    cin >> p >> n >> x;
    int res1 = getCol(x) + getRow(x) - 2;
    int res2 = getCol(n) + getCol(n) - getCol(x) + abs(getRow(n) - getRow(x));
    int res3 = getCol(x) + 1 + p - getRow(x);

    cout << min(res3, min(res1, res2)) << '\n';
    return 0;
}
