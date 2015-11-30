#include <bits/stdc++.h>

using namespace std;

int n, a[2000];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
    if (a[j] < a[i])
    {
        cout << "no";
        return 0;
    }
    cout << "yes";
    return 0;
}
