#include <bits/stdc++.h>

using namespace std;

int n;
string res;

int main()
{
    cin >> n;
    if (n == 0) { cout << 10; return 0; }
    if (n == 1) { cout << 1; return 0; }
    for (int i = 9; i >= 2 && n != 1; --i)
    {
        while (n % i == 0)
        {
            res.push_back('0' + i);
            n /= i;
        }
    }

    if (n != 1) { cout << -1; return 0; }

    reverse(res.begin(), res.end());
    cout << res;

    return 0;
}
