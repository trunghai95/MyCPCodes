#include <bits/stdc++.h>

using namespace std;

int n, k, res;

int main()
{
    while (!cin.eof())
    {
        cin >> n >> k;
        res = n;
        while (n >= k)
        {
            res += n/k;
            n = n/k + n%k;
        }
        cout << res << endl;
    }
    return 0;
}
