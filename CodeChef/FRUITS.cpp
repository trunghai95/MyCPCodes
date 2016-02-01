#include <bits/stdc++.h>

using namespace std;

int test, n, m, k;

int main()
{
    cin >> test;

    while (test--)
    {
        cin >> n >> m >> k;
        if (n < m) swap(n, m);
        cout << max(n - m - k, 0) << '\n';
    }
    return 0;
}
