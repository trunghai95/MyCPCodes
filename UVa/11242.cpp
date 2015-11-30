#include <bits/stdc++.h>

using namespace std;

int f, r, fs[11], rs;
vector<double> d;
double res;

int main()
{
    while (1)
    {
        d.clear();
        cin >> f;
        if (!f)
            return 0;
        cin >> r;
        for (int i = 0; i < f; ++i)
            cin >> fs[i];
        for (int i = 0; i < r; ++i)
        {
            cin >> rs;
            for (int j = 0; j < f; ++j)
                d.push_back((1.0*rs)/(1.0*fs[j]));
        }
        sort(d.begin(),d.end());
        res = 0;
        for (int i = 1; i < d.size(); ++i)
        {
            if (d[i]/d[i-1] > res)
                res = d[i]/d[i-1];
        }
        printf("%.2lf\n",res);
    }
    return 0;
}
