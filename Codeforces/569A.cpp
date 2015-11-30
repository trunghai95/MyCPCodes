#include <bits/stdc++.h>

using namespace std;

double T, S, q;
int cnt;

int main()
{
    cin >> T >> S >> q;
    while (S < T)
    {
        S = S*q;
        ++cnt;
    }
    cout << cnt;
    return 0;
}
