#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b;

int main()
{
    cin >> a >> b;
    ll tong = a*(b+1) + b*(a+1);
    if (tong & 1)
    {
        tong /= 2;
        if (!(tong & 1))
            --tong;
    }
    else
    {
        tong /= 2;
        if (tong & 1)
            --tong;
    }
    cout << tong;
    return 0;
}
