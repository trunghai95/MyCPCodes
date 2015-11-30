#include <bits/stdc++.h>

using namespace std;

int test, h1, m1, h2, m2;
string s1, s2;

int main()
{
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	cin >> test;
	while (test--)
    {
        cin >> s1 >> s2;
        s1[2] = s2[2] = ' ';
        stringstream ss1, ss2;
        ss1 << s1; ss2 << s2;
        ss1 >> h1 >> m1;
        ss2 >> h2 >> m2;
        int res = m2 - m1;
        if (res < 0) res += 60;
        res = min(res, 60-res);
        int tmp = h2 - h1;
        if (tmp < 0) tmp += 12;
        tmp = min(tmp, 12-tmp);
        res += tmp;
        cout << res << endl;
    }

    return 0;
}
