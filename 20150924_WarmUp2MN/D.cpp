#include <bits/stdc++.h>

using namespace std;

int test, n, b, cNum, lNum, xx;
string s, tmp, a;

int f(int pos)
{
    int res = 0;
    if (s[pos] >= 'A') res = 16*(10 + s[pos] - 'A');
    else res = 16*(s[pos] - '0');

    if (s[pos+1] >= 'A') res += (10 + s[pos+1] - 'A');
    else res += (s[pos+1] - '0');

    return res;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> test;
    while (test--)
    {
        tmp.clear();
        s.clear();
        a.clear();
        cin >> n >> b;
        cNum = b*2;
        lNum = cNum / 80 + (cNum % 80 > 0);
        for (int ii = 0; ii < lNum; ++ii)
        {
            cin >> tmp;
            s += tmp;
        }
        int i = 0;

        while (1)
        {
            if (i >= cNum)
                break;

            if ((xx = f(i)) <= 127)
            {
                ++xx;
                for (int ii = 0; ii < xx; ++ii)
                {
                    i += 2;
                    a.push_back(s[i]); a.push_back(s[i+1]);
                }
            }
            else
            {
                xx += 3 - 128;
                i += 2;
                for (int ii = 0; ii < xx; ++ii)
                {
                    a.push_back(s[i]); a.push_back(s[i+1]);
                }
            }

            i += 2;
        }

        lNum = a.size() / 80 + (a.size() % 80 > 0);
        cout << n << ' ' << a.size() / 2 << endl;
        for (int ii = 1; ii < lNum; ++ii)
        {
            cout << a.substr((ii-1)*80, 80) << endl;
        }

        cout << a.substr((lNum-1)*80, 80) << endl;
    }
    return 0;
}
