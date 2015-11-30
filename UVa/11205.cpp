#include <bits/stdc++.h>

using namespace std;

int t, p, n, b[100], tmp, res, j;
bool ck[1<<15];

int cnt(int i)
{
    int res=0;
    while (i)
    {
        res += (i&1);
        i = i >> 1;
    }
    return res;
}

int main()
{
    cin >> t;
    while (t--)
    {
        memset(b,0,sizeof(b));
        cin >> p >> n;
        res = p;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < p; ++j)
            {
                cin >> tmp;
                b[i] = b[i] << 1;
                b[i] = b[i] | tmp;
            }
        }
        for (int i = 0; i < (1<<p); ++i)
        {
            memset(ck,0,sizeof(ck));
            for (j = 0; j < n; ++j)
            {
                if (ck[i&b[j]])
                    break;
                ck[i&b[j]] = 1;
            }
            if (j == n && cnt(i) < res)
                res = cnt(i);
        }
        cout << res << endl;
    }
    return 0;
}
