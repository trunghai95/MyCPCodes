#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000001;
int n, a[MAX], h[MAX];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> h[i];
    }
    a[n-1] = 0;
    for (int i = n - 2; i >= 0; --i)
    {
        a[i] = max(0, h[i+1] + 1 - h[i]);
        h[i] = max(h[i], h[i+1]);
    }

    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    return 0;
}
