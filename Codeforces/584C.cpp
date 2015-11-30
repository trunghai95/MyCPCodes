#include <bits/stdc++.h>

using namespace std;

int n, t, cnt;
char s[3][100010];
bool ck[100010];

int main()
{
    cin >> n >> t >> s[0] >> s[1];
    memset(ck, 0, sizeof(ck));
    s[2][n] = '\0';

    cnt = 0;

    t = n - t;

    for (int i = 0; i < n; ++i)
    {
        if (s[0][i] == s[1][i])
        {
            ++cnt;
            if (t) --t, s[2][i] = s[0][i], ck[i] = 1;
        }
    }

    if (t == 0)
    {
        for (int i = 0; i < n; ++i)
        {
            if (!ck[i])
            {
                s[2][i] = 'a';
                while (s[2][i] == s[1][i] || s[2][i] == s[0][i])
                    ++s[2][i];
            }
        }

        cout << s[2];
        return 0;
    }

    cnt = n - cnt;

    if (t*2 > cnt) { cout << -1; return 0; }

    int tmp = t;

    for (int i = 0; i < n && tmp; ++i)
    {
        if (!ck[i]) ck[i] = 1, s[2][i] = s[0][i], --tmp;
    }

    tmp = t;

    for (int i = 0; i < n && tmp; ++i)
    {
        if (!ck[i]) ck[i] = 1, s[2][i] = s[1][i], --tmp;
    }

    for (int i = 0; i < n; ++i)
    {
        if (!ck[i])
        {
            s[2][i] = 'a';
            while (s[2][i] == s[1][i] || s[2][i] == s[0][i])
                ++s[2][i];
        }
    }

    cout << s[2];

    return 0;
}
