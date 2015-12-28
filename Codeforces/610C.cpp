//WA
#include <bits/stdc++.h>

using namespace std;

int k, kk, line, cnt;
char s1[400], s2[400];

void solve(int p)
{
    if (line == 0)
        return;
    if (cnt == kk)
    {
        cout << s1 << s1 << '\n' << s1 << s2 << '\n';
        line -= 2;
        return;
    }

    for (int i = p; line && i < (k >> 1); ++i)
    {
        s1[i] = '*', s2[i] = '+';
        ++cnt;
        solve(i + 1);
        --cnt;
        s1[i] = '+', s2[i] = '*';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> k;
    if (k == 0)
    {
        cout << "+";
        return 0;
    }

    k = 1 << k;
    kk = k >> 2;

    for (int i = 0; i < k; ++i)
        cout << "+";
    cout << '\n';
    for (int i = (k >> 1); i > 0; --i)
        cout << "+";
    for (int i = (k >> 1); i > 0; --i)
        cout << "*";
    cout << '\n';
    for (int i = 0; i < (k >> 1); ++i)
        s1[i] = '+', s2[i] = '*';

    line = k - 2;
    cnt = 0;

    solve(0);
    return 0;
}
