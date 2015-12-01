#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll x[5] = {500,1000,1500,2000,2500};
ll m[5], w[5], hs, hu;

int main()
{
    for (int i = 0; i < 5; ++i)
        cin >> m[i];
    for (int i = 0; i < 5; ++i)
        cin >> w[i];
    cin >> hs >> hu;

    double res = 0;

    for (int i = 0; i < 5; ++i)
        res += max(0.3*x[i], (1.0 - 1.0*m[i]/250)*x[i] - 50*w[i]);

    res += 100.0*hs - 50.0*hu;

    cout << res;
    return 0;
}
