#include <bits/stdc++.h>

using namespace std;

typedef pair<int, string> pis;

int test, n;
pis a[200];

int proc(string &tmp)
{
    int p = 0;
    while ((p = tmp.find('-', p)) != tmp.npos)
        tmp[p] = ' ';

    stringstream str(tmp);
    string x;

    int bb = 1, res = 0;
    int cnt = 0;
    while (str >> x)
    {
        ++cnt;
        if (x == "middle")
            res += 1*bb;
        else if (x == "upper")
            res += 2*bb;
        bb *= 3;
    }

    while (cnt < 10)
        res = res*3 + 1, ++cnt;

    return 1000000000 - res;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> test;

    while (test--)
    {
        cin >> n;
        string tmp;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i].second >> tmp;
            a[i].second.erase(a[i].second.end() - 1);
            a[i].first = proc(tmp);
            cin >> tmp;
        }

        sort(a, a+n);
        for (int i = 0; i < n; ++i)
            cout << a[i].second << '\n';

        for (int i = 0; i < 30; ++i)
            cout << '=';
        cout << '\n';
    }
    return 0;
}
