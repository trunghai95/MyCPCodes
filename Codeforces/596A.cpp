#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef pair<int, int> pii;

pii p[4];
int n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> p[i].F >> p[i].S;

    if (n < 2)
        cout << -1;
    else if (n == 2)
    {
        if (p[0].F == p[1].F || p[0].S == p[1].S)
            cout << -1;
        else
            cout << abs(p[0].F - p[1].F) * abs(p[0].S - p[1].S);
    }
    else
    {
        for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
        if (p[i].F == p[j].F)
        {
            int a = abs(p[i].S - p[j].S);

            for (int x = 0; x < n; ++x)
            for (int y = x+1; y < n; ++y)
            if (p[x].S == p[y].S)
            {
                int b = abs(p[x].F - p[y].F);
                cout << a*b;
                return 0;
            }
        }

        cout << -1;
    }
    return 0;
}
