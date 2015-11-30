#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y)
{
    if (!x || !y) return x+y;
    return (x > y) ? gcd(x % y, y) : gcd(y % x, x);
}

bool pp(int x)
{
    int tmp = x;
    int y = 0;

    while (tmp)
    {
        y = y*10 + tmp%10;
        tmp /= 10;
    }

    return (gcd(x,y) == 1);
}

int main()
{
    int a, b;
    int res = 0;
    cin >> a >> b;
    for (int i = a; i <= b; ++i)
        res += pp(i);

    cout << res;
    return 0;
}
