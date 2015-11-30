#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int sad = 0, smile = 0;
    string s;
    cin >> n >> s;

    for (int i = 1; i < s.length(); ++i)
    {
        if ((s[i] == ':' && s[i-1] == ')') || (s[i] == '(' && s[i-1] == ':'))
            ++sad;
        if ((s[i] == ':' && s[i-1] == '(') || (s[i] == ')' && s[i-1] == ':'))
            ++smile;
    }
    if (sad > smile) cout << "SAD";
    else if (sad < smile) cout << "HAPPY";
    else cout << "BORED";
    return 0;
}
