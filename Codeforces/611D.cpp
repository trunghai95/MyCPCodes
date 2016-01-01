//TLE
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MODD = 1e9 + 7;

int n;
char s[6000];

ll solve(char *s, int minLen, char *prev)
{
    if (s[0] == '0')
        return 0;
    int len = strlen(s);
    if (minLen > (len >> 1))
    {
        if (minLen < len) return 1;
        if (minLen > len) return 0;
        for (int i = 0; i < minLen; ++i)
        {
            if (s[i] > prev[i])
                return 1;
            if (s[i] < prev[i])
                return 0;
        }
        return 0;
    }

    ll res = 1;
    if (prev != NULL)
    {
        int f = 0;
        for (int i = 0; i < minLen && !f; ++i)
            f = s[i] - prev[i];
        if (f > 0)
            res = (res + solve(s + minLen, minLen, s)) % MODD;
    }
    else
        res = (res + solve(s + 1, 1, s)) % MODD;

    for (int i = minLen + 1; i <= (len >> 1); ++i)
    if (s[i] != '0')
        res = (res + solve(s + i, i, s));

    return res;
}

int main()
{
    cin >> n >> s;

    if (strlen(s) != 1)
        cout << solve(s, 1, NULL);
    else
        cout << 1;
    return 0;
}
