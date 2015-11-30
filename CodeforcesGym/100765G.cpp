#include <bits/stdc++.h>

using namespace std;

#define UP 0
#define DOWN 1

string s, res;

char up(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A';
    return c;
}

char down(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    return c;
}

int main()
{
    cin >> s;
    stack<int> st;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] != '<')
        {
            if (st.empty())
                res.push_back(s[i]);
            else if (st.top() == UP)
                res.push_back(up(s[i]));
            else res.push_back(down(s[i]));
        }
        else
        {
            if (s[i+1] == '/')
            {
                st.pop();
                if (s[i+2] == 'U')
                    i += 4;
                else i += 6;
            }
            else if (s[i+1] == 'U')
            {
                st.push(UP);
                i += 3;
            }
            else { st.push(DOWN); i += 5; }
        }
    }

    cout << res;
    return 0;
}
