#include <bits/stdc++.h>

using namespace std;

int cc[3], t;

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> cc[0] >> cc[1] >> cc[2];
        sort(cc,cc+3);

        int a = cc[0] + cc[1], b;

        if (cc[2] >= a*2)
        {
            cout << a << endl;
        }
        else if (cc[2] >= a)
        {
            b = cc[2] - a;
            cout << b + 2*(a-b)/3 << endl;
        }
        else
        {
            b = a - cc[2];
            a = cc[2];
            cout << b + 2*((a-b)/3) << endl;
        }
    }
    return 0;
}
