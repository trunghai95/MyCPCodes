#include <bits/stdc++.h>

using namespace std;

int n, b, h, w, p, pmin = 1e9, a, j, f;

int main()
{
    while (!cin.eof())
    {
        pmin = 1e9;
        cin >> n >> b >> h >> w;
        for (int i = 0; i < h; ++i)
        {
            cin >> p;
            p*=n;
            f = 0;
            for (j = 0; j < w; ++j)
            {
                cin >> a;
                if (a >= n)
                    f = 1;
            }
            if (p < pmin && p <= b && f)
                pmin = p;
        }
        if (pmin == 1e9)
            cout << "stay home" << endl;
        else
            cout << pmin << endl;
    }
    return 0;
}
