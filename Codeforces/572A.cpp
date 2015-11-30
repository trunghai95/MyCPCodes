#include <bits/stdc++.h>

using namespace std;

int na, nb, k, m, a[111111], b[111111], ta, tb;

int main()
{
    cin >> na >> nb >> k >> m;
    for (int i = 1; i <= na; ++i) cin >> a[i];
    for (int i = 1; i <= nb; ++i) cin >> b[i];
    if (a[k] < b[nb - m + 1]) cout << "YES";
    else cout << "NO";
    return 0;
}
