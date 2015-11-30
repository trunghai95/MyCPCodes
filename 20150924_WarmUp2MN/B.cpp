#include <bits/stdc++.h>

using namespace std;

int test, n, b, x, y, sum, lt;

int main()
{
    //freopen("in.txt", "r", stdin);
    cin >> test;
    while (test--)
    {
        cin >> n >> b >> x >> y;
        lt = 1; sum = 0;
        while (x || y)
        {
            sum += lt * (((x%b) + (y%b)) % b);
            lt *= b;
            x /= b;
            y /= b;
        }

        cout << n << ' ' << sum << endl;
    }
    return 0;
}
