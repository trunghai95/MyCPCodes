#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sumofdigits(ll n)
{
    if (n < 10) return n;
    return sumofdigits(n/10) + (n%10);
}

ll digitsum(ll n)
{
    if (n < 10)
        return (n * (n + 1) / 2);

    ll res = (n/10) * 45 + digitsum(n % 10);
    res += ((n % 10) + 1) * sumofdigits(n/10) + digitsum(n/10 - 1) * 10;
    return res;
}

int main()
{
    int test;
    ll a, b;
    cin >> test;
    while (test--)
    {
        cin >> a >> b;
        ll x = digitsum(b);
        ll y = digitsum(a-1);
        cout << digitsum(b) - digitsum(a-1) << endl;
    }
    return 0;
}
