#include <bits/stdc++.h>

using namespace std;

int n, i, j, b;
string s;

int main()
{
    cin >> n >> s;
    b = 0;

        for (i = b; i < s.size()-1; ++i)
        {
            if (s[i] == s[i+1])
                b = i;
            else
            {
                s.erase(i, 2);
                i = b-1;
            }
        }

    cout << s.size();

    return 0;
}
