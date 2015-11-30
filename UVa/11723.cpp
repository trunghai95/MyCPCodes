#include <bits/stdc++.h>

using namespace std;

int r, n, d, i;

int main()
{
    while (1)
    {
        ++i;
        cin >> r >> n;
        if (r == 0 && n == 0)
            return 0;
        if (r <= n)
            d = 0;
        else
        {
            r -= n;
            d = r/n + (r%n > 0);
        }

        printf("Case %d: ",i);
        if (d > 26)
            cout << "impossible\n";
        else
            cout << d << endl;
    }
    return 0;
}
