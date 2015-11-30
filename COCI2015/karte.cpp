#include <bits/stdc++.h>

using namespace std;

bool ck[300][20];
string s;

int main()
{
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	cin >> s;

	memset(ck, 0, sizeof(ck));

	for (int i = 0; i < s.length(); i += 3)
    {
        int val = 10*s[i+1] + s[i+2] - 11*'0';
        if (ck[s[i]][val])
        {
            cout << "GRESKA";
            return 0;
        }
        ck[s[i]][val] = 1;
    }

    int p = 0, k = 0, h = 0, t = 0;
    for (int i = 1; i <= 13; ++i)
    {
        p += 1 - ck['P'][i];
        k += 1 - ck['K'][i];
        h += 1 - ck['H'][i];
        t += 1 - ck['T'][i];
    }

    cout << p << ' ' << k << ' ' << h << ' ' << t;

    return 0;
}
