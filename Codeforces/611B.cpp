#include <bits/stdc++.h>

using namespace std;

const int MAXBIT = 62;

typedef long long ll;

ll a, b;

int main()
{
    cin >> a >> b;
    ll res = 0;
    for (int i = 0; i < MAXBIT; ++i)
    {
        ll tmp = (1LL << i) - 1;
        for (int j = i + 1; j <= MAXBIT; ++j)
        {
            tmp = tmp | (1LL << j);
            if (tmp >= a && tmp <= b)
                ++res;
        }
    }

    cout << res;
    return 0;
}
