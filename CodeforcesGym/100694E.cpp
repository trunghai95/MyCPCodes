#include <bits/stdc++.h>

using namespace std;

typedef pair<double,int> pdi;

int n, k, c[100000], i, j, tmp, minPos;
double p[100000][2], x[100000], _min;
set<pdi> data;

int main()
{
    cin >> n >> k;
    memset(c, 0, sizeof(c));
    memset(p, 0, sizeof(p));
    memset(x, 0, sizeof(x));
    _min = 10000000;
    for (i = 0; i < n && i < k; ++i)
    {
        cin >> tmp;
        p[i][1] = x[i] = tmp;
        c[i] = 1;
        cout << i + 1 << " ";
        data.insert(pdi(x[i],i));
    }
    if (n <= k)
        return 0;

    for (i = k; i < n; ++i)
    {
        cin >> tmp;
        minPos = (*data.begin()).second;
        cout << (*data.begin()).second + 1 << " ";
        ++c[minPos];
        swap(p[minPos][0], p[minPos][1]);
        p[minPos][1] = tmp;
        x[minPos] = 1.0*c[minPos]*(p[minPos][0] + p[minPos][1])/2;
        data.erase(data.begin());
        data.insert(pdi(x[minPos],minPos));
    }
    return 0;
}
