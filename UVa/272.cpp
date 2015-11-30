#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    string c;
    int open = 0;

    while (getline(cin, c))
    {
        for (int i = 0; i < c.size(); ++i)
        {
            if (c[i] == '\"')
            {
                if (open)
                    cout << "\'\'";
                else
                    cout << "\`\`";
                open = 1 - open;
            }
            else
                cout << c[i];
        }

        cout << '\n';
    }
    return 0;
}
