#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef pair<int,int> pii;
int n, m, p[8], res, i;
pair<pii,int> c[20];

int main()
{
    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            return 0;
        res = 0;
        for (i = 0; i < n; ++i)
            p[i] = i;
        for (i = 0; i < m; ++i)
            cin >> c[i].F.F >> c[i].F.S >> c[i].S;
        do
        {
            for (i = 0; i < m; ++i)
            {
                if (c[i].S > 0 && abs(p[c[i].F.F] - p[c[i].F.S]) > c[i].S)
                    break;
                if (c[i].S < 0 && abs(p[c[i].F.F] - p[c[i].F.S]) < -c[i].S)
                    break;
            }
            if (i == m)
                ++res;
        }
        while (next_permutation(p,p+n));
        cout << res << endl;
    }
    return 0;
}
