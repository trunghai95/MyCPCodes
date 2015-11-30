#include <bits/stdc++.h>

using namespace std;

int n, t, res;
bool ck[111];
char s[111];

void lit(int x)
{
    ck[x] = 1;
    if (x == 0)
    {
        ck[1] = 1;
        return;
    }
    if (x == n-1)
    {
        ck[n-2] = 1;
        return;
    }
    ck[x-1] = ck[x+1] = 1;
}

int main()
{
    cin >> t;
    while (t--)
    {
        res = 0;
        memset(ck,0,sizeof(ck));
        cin >> n >> s;
        for (int i = 0; i < n; ++i)
        if (s[i] == '*')
            lit(i);

        for (int i = 0; i < n; ++i)
        if (!ck[i])
        {
            if (i < n-1 && s[i+1] != '*')
                lit(i+1);
            else lit(i);
            ++res;
        }
        cout << res << endl;
    }
    return 0;
}
