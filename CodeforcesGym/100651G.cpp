#include <bits/stdc++.h>

using namespace std;

char in[300], a[300][300];
int n, m, c;

int main()
{
    while (1)
    {
        memset(a,0,sizeof(a));
        cin >> n;
        if (n == 0)
            return 0;
        cin >> in;
        m = strlen(in)/n;
        if (strlen(in)%n) ++m;
        c = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
                if (i&1)
                    a[i][n-j-1] = in[c++];
                else
                    a[i][j] = in[c++];
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            if (a[j][i] != 0)
                cout << a[j][i];
        cout << endl;
    }
    return 0;
}
