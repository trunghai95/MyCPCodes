#include <bits/stdc++.h>

using namespace std;

int n, p, q;
string s;

int main()
{
    cin >> n >> p >> q >> s;

    for (int pp = 0; pp <= n; pp += p)
    {
        int qq = n - pp;
        if (qq % q == 0)
        {
            pp/=p, qq/=q;
            cout << pp+qq << '\n';
            for (int i = 0; i < pp; ++i)
            {
                cout << string(s, i*p, p) << '\n';
            }
            for (int i = 0; i < qq; ++i)
            {
                cout << string(s, i*q + p*pp, q) << '\n';
            }
            return 0;
        }
    }

    cout << -1;
    return 0;
}
