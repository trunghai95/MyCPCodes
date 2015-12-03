#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000010;

char s[MAXN];
int z[MAXN], n;

void initz()
{
    int L = 0, R = 0;

    for (int i = 1; i < n; ++i)
    {
        if (i > R)
        {
            L = R = i;
            while (R < n && s[R] == s[R-L]) ++R;

            z[i] = R - L;
            --R;
        }
        else
        {
            int k = i - L;

            if (z[k] < R - i + 1)
                z[i] = z[k];
            else
            {
                L = i;

                while (R < n && s[R] == s[R-L]) ++R;

                z[i] = R - L;
                --R;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> s;

    n = strlen(s);
    initz();

    int maxz = 0, res = -1;

    for (int i = 1; i < n; ++i)
    {
        if (z[i] == n-i && maxz >= z[i])
        {
            res = z[i];
            break;
        }

        maxz = max(maxz, z[i]);
    }

    if (res == -1)
        cout << "Just a legend";
    else
    {
        for (int i = 0; i < res; ++i)
            cout << s[i];
    }

    return 0;
}
