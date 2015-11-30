#include <bits/stdc++.h>

using namespace std;

int t, n;

int main()
{
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	cin >> t;
	while (t--)
    {
        cin >> n;
        bool f = 0;
        int k = 1;

        while (!f)
        {
            int tu = 2*n - k*(k+1);
            if (tu < 0) break;
            int mau = 2*(k+1);
            if (tu % mau == 0)
            {
                f = 1;
                tu = tu/mau;

                cout << n << " = ";
                for (int i = 0; i < k; ++i)
                    cout << tu + i << " + ";

                cout << tu + k << endl;
            }
            ++k;
        }

        if (!f) cout << "IMPOSSIBLE\n";
    }

    return 0;
}
