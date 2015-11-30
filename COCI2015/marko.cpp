#include <bits/stdc++.h>

using namespace std;

char k[200];
string dict[3000];
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    k['a'] = k['b'] = k['c'] = '2';
    k['d'] = k['e'] = k['f'] = '3';
    k['g'] = k['h'] = k['i'] = '4';
    k['j'] = k['k'] = k['l'] = '5';
    k['m'] = k['n'] = k['o'] = '6';
    k['p'] = k['q'] = k['r'] = k['s'] = '7';
    k['t'] = k['u'] = k['v'] = '8';
    k['w'] = k['x'] = k['y'] = k['z'] = '9';

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> dict[i];
        for (int j = 0; j < dict[i].length(); ++j)
            dict[i][j] = k[dict[i][j]];
    }

    string pr;
    cin >> pr;
    int res = 0;
    for (int i = 0; i < n; ++i)
        res += (pr == dict[i]);

    cout << res;
    return 0;
}
