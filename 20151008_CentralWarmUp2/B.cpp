#include <bits/stdc++.h>

using namespace std;

int m, n, test;
string q[30];

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> test;
    while (test--)
    {
        cin >> m >> n;
        for (int i = 1; i <= m; ++i)
            cin >> q[i];
        for (int i = 0; i < n; ++i)
        {
            int x, y;
            cin >> x >> y;
            if (x == y) continue;
            string tmp = q[x];
            if (x > y)
            {
                for (int j = x; j > y; --j)
                    q[j] = q[j-1];
                q[y] = tmp;
                cout << q[1] << ' ' << q[2] << ' ' << q[3] << endl;
            }
            else
            {
                for (int j = x; j < y; ++j)
                    q[j] = q[j+1];
                q[y] = tmp;
                cout << q[1] << ' ' << q[2] << ' ' << q[3] << endl;
            }
        }

        for (int i = 1; i <= m; ++i)
            cout << q[i] << ' ';
        cout << endl;
    }
    return 0;
}
