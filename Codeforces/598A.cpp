#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test;
ll n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> test;
    while (test--)
    {
        cin >> n;
        ll res = n*(n+1)/2;
        ll tmp = 1;
        while (tmp <= n) tmp <<= 1;
        tmp = (tmp - 1)*2;
        res -= tmp;
        cout << res << '\n';
    }
    return 0;
}
