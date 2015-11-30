#include <bits/stdc++.h>

using namespace std;

int n, m, x, res;
char s[300007], c;

int main()
{
    res = 0;
    cin >> n >> m >> s;
    for (int i = 1; i < n; ++i)
    if (s[i] == '.' && s[i-1] == '.')
        ++res;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> c;
        --x;
        if (s[x] != '.' && c == '.')
            res += (x > 0 && s[x-1] == '.') + (x < n-1 && s[x+1] == '.');
        else if (s[x] == '.' && c != '.')
            res -= (x > 0 && s[x-1] == '.') + (x < n-1 && s[x+1] == '.');
        cout << res << endl;
        s[x] = c;
    }
    return 0;
}
