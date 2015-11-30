#include <bits/stdc++.h>

using namespace std;

int n, i, j, x;
stack<int> st;
string str;

int main()
{
    cin >> n;
    cin >> str >> x;
    st.push(x);
    for (i = 2*n; i > 1; --i)
    {
        cin >> str >> x;
        if (str == "in")
        {
            cout << st.top() << " " << x << endl;
            st.push(x);
        }
        if (str == "out")
            st.pop();
    }
    return 0;
}
