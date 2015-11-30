#include <bits/stdc++.h>

using namespace std;

int n, a, b, r, res;

int main()
{
    cin >> n;
    a = 0;
    r = n;
    while (1)
    {
        if (r < 0 || r%5 == 0)
            break;
        r -= 3;
        a += 1;
    }

    if (r < 0)
        res = -1;
    else
        res = a + r/5;

    cout << res;
    return 0;
}
