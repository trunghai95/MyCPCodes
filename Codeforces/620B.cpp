#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll d[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

ll f(int x)
{
    ll res = 0;
    while (x)
    {
        res += d[x % 10];
        x /= 10;
    }

    return res;
}

int main()
{
    ll res = 0;
    int a, b;

    cin >> a >> b;
    for (int i = a; i <= b; ++i)
        res += f(i);

    cout << res;
    return 0;
}
