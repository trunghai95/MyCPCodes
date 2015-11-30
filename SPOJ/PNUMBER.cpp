#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000;
bool pr[maxn + 1];

int main()
{
    memset(pr, -1, sizeof(pr));

    pr[0] = pr[1] = 0;

    for (int i = 2; i*i <= maxn; ++i)
    if (pr[i])
    {
        for (int u = i*i; u <= maxn; u += i)
            pr[u] = 0;
    }

    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; ++i)
    {
        if (pr[i]) cout << i << ' ';
    }
    return 0;
}
