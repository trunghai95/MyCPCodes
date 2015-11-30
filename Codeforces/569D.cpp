#include <bits/stdc++.h>

using namespace std;

const long long oo = 1e9 + 7;
long long n, f[5000] = {0,1,3,10};

int main()
{
    cin >> n;
    if (n <= 3)
    {
        cout << f[n];
        return 0;
    }
    for (int i = 4; i <= n; ++i)
        f[i] = f[i-1]*i%oo + 1;
    cout << f[n]%oo;
    return 0;
}
