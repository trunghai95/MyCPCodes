#include <bits/stdc++.h>

using namespace std;

string in, res;

string add(string &x, string &y)
{
    if (x.size() > y.size())
        y.insert(0,x.size()-y.size(),'0');
    if (y.size() > x.size())
        x.insert(0,y.size()-x.size(),'0');
    int f = 0, tmp;
    string res;
    for (int i = x.size()-1; i >= 0; --i)
    {
        tmp = f + x[i] - '0' + y[i] - '0';
        switch (tmp)
        {
        case 0: case 1:
            res.insert(res.begin(), '0' + tmp);
            f = 0;
            break;
        case 2: case 3:
            res.insert(res.begin(), '0' + tmp - 2);
            f = 1;
            break;
        }
    }
    if (f == 1)
        res.insert(res.begin(), '1');
    return res;
}

int main()
{
    cin >> in;
    res = in;
    for (int i = 0; i < 16; ++i)
        res = add(res,in);
    cout << res;
    return 0;
}
