#include <bits/stdc++.h>

using namespace std;

int n, a, b, sum;

int main()
{
    sum = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> b;
        a = i*b - sum;
        sum += a;
        cout << a << " ";
    }
    return 0;
}
