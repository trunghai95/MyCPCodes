#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    if (t == 10) --n;
    if (n == 0) { cout << -1; return 0; }

    cout << t;
    for (int i = 1; i < n; ++i)
        cout << 0;
    return 0;
}
