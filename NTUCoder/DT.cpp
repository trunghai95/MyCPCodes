#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

int main()
{
    cin >> n;
    ll cur = 0, last = 0;

    while (1)
    {
        ++cur;
        last -= last % cur;
        if (n <= cur)
        {
            cout << last + n*cur;
            return 0;
        }
        else
        {
            n -= cur;
            last += cur*cur;
        }
    }
    return 0;
}
