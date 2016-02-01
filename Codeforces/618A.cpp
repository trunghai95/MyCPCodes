#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> st;

int main()
{
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        st.push_back(1);

        while (st.size() > 1 && st[st.size() - 1] == st[st.size() - 2])
        {
            int x = st.back();
            st.pop_back();
            st.pop_back();
            st.push_back(x+1);
        }
    }

    for (int i = 0; i < st.size(); ++i)
        printf("%d ", st[i]);
    return 0;
}
