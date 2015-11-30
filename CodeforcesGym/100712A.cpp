#include <bits/stdc++.h>

using namespace std;

int t, n, s, p, smax, pmax;
char name[30], namemax[30];

int main()
{
    cin >> t;
    while (t--)
    {
        smax = pmax = 0;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> name >> s >> p;
            if (s > smax || (s == smax && p < pmax))
            {
                strcpy(namemax,name);
                smax = s;
                pmax = p;
            }
        }
        cout << namemax << endl;
    }
    return 0;
}
