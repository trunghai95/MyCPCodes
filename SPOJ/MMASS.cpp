#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<int> st;
    int tmp;

    for (int i = 0; i < s.size(); ++i)
    {
        switch(s[i])
        {
        case '(':
            st.push(-1);
            break;
        case 'C':
            st.push(12);
            break;
        case 'O':
            st.push(16);
            break;
        case 'H':
            st.push(1);
            break;
        case ')':
            tmp = 0;
            while (st.top() != -1)
                tmp += st.top(), st.pop();
            st.pop();
            st.push(tmp);
            break;
        default:
            tmp = st.top();
            tmp *= (int)(s[i] - '0');
            st.pop();
            st.push(tmp);
        }
    }

    tmp = 0;
    while (!st.empty())
        tmp += st.top(), st.pop();

    cout << tmp;
    return 0;
}
