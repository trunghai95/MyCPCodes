#include <bits/stdc++.h>

using namespace std;

int m, n, a;

int main()
{
    cin >> n >> m;
    if (n == 1)
        a = 1;
    else if (m <= n/2)
        a = m+1;
    else
        a = m-1;
    cout << a;
    return 0;
}
