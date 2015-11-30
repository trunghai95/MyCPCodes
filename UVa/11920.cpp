#include <bits/stdc++.h>

using namespace std;

int t, n, curNode;
int a[111][111], res[111][111], ck[111];
char s[210];

void dfs(int node)
{
    ck[node] = 1;
    if (curNode != node)
        res[curNode][node] = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[node][i] && !ck[i])
            dfs(i);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> t;
    for (int ti = 1; ti <= t; ++ti)
    {
        memset(res,1,sizeof(res));
        cin >> n;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> a[i][j];
        for (int i = 1; i < n; ++i)
        {
            memset(ck,0,sizeof(ck));
            ck[i] = 1;
            curNode = i;
            dfs(0);
        }

        for (int i = 0; i < 2*n+1; ++i)
            s[i] = '-';
        s[0] = s[2*n] = '+';
        s[2*n+1] = 0;
        cout << "Case " << ti << ":\n";
        cout << s << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << '|';
            for (int j = 0; j < n; ++j)
            {
                if (res[i][j])
                    cout << "Y|";
                else
                    cout << "N|";
            }
            cout << endl << s << endl;
        }
    }
    return 0;
}
