#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;

int n, m, arr[MAX+1];

int gcd(int x, int y)
{
    if (!x || !y) return x+y;
    return (x > y) ? gcd(x%y, y) : gcd(y%x, x);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int test;
    cin >> test;

    while (test--)
    {
        cin >> n >> m;
        int cnt = n / gcd(n, m);

        if (cnt == n)
            cout << "Yes\n";
        else
            cout << "No " << cnt << '\n';
    }

    return 0;
}
