#include <bits/stdc++.h>

using namespace std;

char s[1000010];
int n;
char d[] = "<{[(-)]}>";

int getID(char c)
{
    for (int i = 0; i < 9; ++i)
    if (c == d[i])
        return i - 4;
    return -1000000;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%s", s);
    n = strlen(s);

    stack<int> st;

    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        int id = getID(s[i]);

        if (id < 0)
            st.push(id);
        else
        {
            if (st.empty())
            {
                printf("Impossible");
                return 0;
            }

            if (st.top() + id)
                ++res;
            st.pop();
        }
    }

    if (st.empty())
        printf("%d", res);
    else
        printf("Impossible");
    return 0;
}
