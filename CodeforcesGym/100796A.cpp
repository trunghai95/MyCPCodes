#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    string a, b;
    cin >> a >> b;
    ll res = 0;

    for (int i = 0; i < a.length(); ++i)
        res = res * 10 + abs(a[i] - b[i]);

    cout << res;
    return 0;
}
