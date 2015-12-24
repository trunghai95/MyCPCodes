#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;

    for (int ii = 0; ii < n; ++ii)
    {
        cin >> s;
        int i = 0;
        string r, c;

        while (s[i] <= 'Z' && s[i] >= 'A')
        {
            c.push_back(s[i]);
            ++i;
        }

        while (i < s.length() && s[i] <= '9' && s[i] >= '0')
        {
            r.push_back(s[i]);
            ++i;
        }

        if (i == s.length())
        {
            int cc = 0;
            for (int j = 0; j < c.length(); ++j)
            {
                cc = cc*26 + c[j] - 'A' + 1;
            }

            cout << 'R' << r << 'C' << cc << '\n';
        }
        else
        {
            int cc = 0;
            ++i;
            while (i < s.length())
            {
                cc = cc*10 + s[i] - '0';
                ++i;
            }
            c.clear();
            while (cc)
            {
                c.insert(c.begin(), 'A' + (cc - 1)%26);
                cc = (cc - 1) / 26;
            }

            cout << c << r << '\n';
        }
    }
    return 0;
}
