#include <bits/stdc++.h>

using namespace std;

bool ck[26];
int n;
char s[100];

int main()
{
    cin >> n >> s;

    if (n < 26)
    {
        cout << "NO";
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            ck[s[i]-'a'] = 1;
        else
            ck[s[i]-'A'] = 1;
    }

    for (int i = 0; i < 26; ++i)
        if (!ck[i])
        {
            cout << "NO";
            return 0;
        }

    cout << "YES";

    return 0;
}
